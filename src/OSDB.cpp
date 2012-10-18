/*
 * OSDB.cpp - Starting class for OSDB (contains main())
 */

/*************************************************************************
 * This file is part of OSDB.                                            *
 *                                                                       *
 * OSDB is free software: you can redistribute it and/or modify          *
 * it under the terms of the GNU General Public License as published by  *
 * the Free Software Foundation, either version 3 of the License, or     *
 * (at your option) any later version.                                   *
 *                                                                       *
 * OSDB is distributed in the hope that it will be useful,               *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 * GNU General Public License for more details.                          *
 *                                                                       *
 * You should have received a copy of the GNU General Public License     *
 * along with OSDB.  If not, see <http://www.gnu.org/licenses/>.         *
 *************************************************************************/

#include "OSDB.h"
#include "SingleUserMode.h"

OSDB::OSDB()
{
	init(0, NULL);
}

OSDB::OSDB(int argc, char** argv)
{
	init(argc, argv);
}

OSDB::~OSDB()
{
	modes.clear(); // Let modes/suites/tests run clean-up before we destroy the DBMS object
	delete config;
	if (logger)
		delete logger;
	delete dbms;
}

void OSDB::init(int argc, char** argv)
{
	loadConfig(argc, argv);
	loadDBModule();
	loadModes();
}

void OSDB::loadConfig(int argc, char** argv)
{
	cout << "Open Source Database Benchmark" << endl;
	string configFilePath = "osdb.conf";
	for (int i = 1; i < argc; i++)
	{
		if ((string)argv[i] == "-f" && i < argc-1)
			configFilePath = argv[++i];
	}
	cout << "Reading configuration file: " << configFilePath << endl;
	config = new Configuration(configFilePath);
	// Retrieve the modes/tests that are enabled
	// Can check the command line arguments to override config settings

	string logFilePath = config->getConfigSetting("main", "logFilePath");
	string useStdOut = config->getConfigSetting("main", "useStdOut");
	logger = new Logger(logFilePath, useStdOut=="true" ? true : false);
}

void OSDB::loadDBModule()
{
	// Read config/command line args to see which DBMS to benchmark

	dbms = new MySQLDB(*config); // MySQLDB will load credentials via config file
	dbms->connect();

	Timer t;
	t.startTimer();
	populator.createTables(dbms);
	double elapsedTime = t.stopTimer();
	(*logger) << (string)"Table creation took " << elapsedTime << (string)" seconds" << endl;

	t.startTimer();
	populator.loadDataset(dbms);
	elapsedTime = t.stopTimer();
	(*logger) << (string)"Dataset load took " << elapsedTime << (string)" seconds" << endl;
}

void OSDB::loadModes()
{
	// Check config/command line args to see which modes to run
	// Load each enabled mode into the modes vector

	// Hardcoded for testing:
	SingleUserMode* testMode = new SingleUserMode(*dbms, *logger);
	modes.push_back(testMode);
}

void OSDB::runBenchmarks()
{
	// Loop through vector of modes and run
	int i;
	for (i = 0; i < modes.size(); i++)
	{
		modes[i]->loadTests();
		modes[i]->runScenario();
	}
}

int main(int argc, char** argv)
{
	OSDB thisInstance(argc, argv);
	thisInstance.runBenchmarks();
	return 0;
}
