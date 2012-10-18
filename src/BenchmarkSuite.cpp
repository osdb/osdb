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

#include "BenchmarkSuite.h"

BenchmarkSuite::BenchmarkSuite(Database& database, Logger& logger) : Benchmark(database, logger)
{
	this->name = "";
}

BenchmarkSuite::BenchmarkSuite(string name, Database& database, Logger& logger) : Benchmark(name, database, logger)
{
}

BenchmarkSuite::BenchmarkSuite(string name, vector<BenchmarkTest*> &tests, Database& database, Logger& logger) : Benchmark(name, database, logger)
{
	this->benchmarks = tests;
}

BenchmarkSuite::~BenchmarkSuite()
{
	benchmarks.clear();
}

void BenchmarkSuite::addTest(BenchmarkTest* newTest)
{
	benchmarks.push_back(newTest);
}

vector<BenchmarkTest*> BenchmarkSuite::getTestsInSuite()
{
	return benchmarks;
}

void BenchmarkSuite::runTest()
{
	for(int i = 0; i < benchmarks.size(); i++) {
//		timer.startTimer();
		benchmarks[i]->runTest();
//		double testTime = timer.stopTimer();
//		log << benchmarks[i]->getName() << (string)" completed in " << testTime << (string)" seconds" << endl;
	}
}


