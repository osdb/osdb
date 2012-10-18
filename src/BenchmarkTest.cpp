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

#include "BenchmarkTest.h"

BenchmarkTest::BenchmarkTest(Database& database, Logger& logger) : Benchmark(database, logger)
{
	string sqlStatement;
}

BenchmarkTest::BenchmarkTest(string testName, string sql, Database& database, Logger& logger) : Benchmark(testName, database, logger)
{
	this->name = testName;
	addSQL(sql);
}


BenchmarkTest::BenchmarkTest(string testName, vector<string> sqlList, Database & database, Logger & logger) : Benchmark(testName, database, logger)
{
	sqls = sqlList;
}

BenchmarkTest::~BenchmarkTest()
{
//	delete sqlStatement;
}

void BenchmarkTest::runTest() {
	// TODO: How do we want to run the tests via SQL?
	//		  ? Pass the SQL to the Database class where it will execute the SQL and return a status
	//		  ? Somehow send down a reference to the Database class where tests could execute themselves



	// For multiple lines for a test, simply loop through the vector of statements and execute each.
	// We leave the timer running since accessing a vector should be fast enough not to skew the results.
	timer.startTimer();	//Begin timing the SQL execution
	db.beginTransaction();
	for (unsigned int i = 0; i < sqls.size(); i++)
	{
		db.execute(sqls[i]);
	}
	db.endTransaction();
	double elapsedTime = timer.stopTimer();

	log << name << " completed in " << elapsedTime << " seconds" << endl;

	// TODO: Determine return - string errlog possibly
}

void BenchmarkTest::addSQL(string SQLLine)
{
	sqls.push_back(SQLLine);
}
