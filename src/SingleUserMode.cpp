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

#include "SingleUserMode.h"
#include "benchmarks/AS3APSuite.cpp"

SingleUserMode::SingleUserMode(Database& database, Logger& logger) : db(database), log(logger), modeName("Single-user Mode")
{
	as3apSuite = new AS3APSuite(db, log);
}

SingleUserMode::~SingleUserMode() {
	delete as3apSuite;
}

void SingleUserMode::runScenario(){
	testTimer.startTimer();
	as3apSuite->runTest();
	double scenarioTime = testTimer.stopTimer();
}

void SingleUserMode::loadTests(){
}


