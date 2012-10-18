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

#ifndef BENCHMARKTEST_H_
#define BENCHMARKTEST_H_

#include <string>
#include <vector>
#include "Timer.h"
#include "Benchmark.h"
#include "Logger.h"
#include "Database.h"

using namespace std;

class BenchmarkTest: public Benchmark
{
private:
	vector<string> sqls;
public:
	BenchmarkTest(Database& database, Logger& logger);
	BenchmarkTest(string testName, string sql, Database& database, Logger& logger);
	BenchmarkTest(string testName, vector<string> sqlList, Database& database, Logger& logger);

	virtual ~BenchmarkTest();

	virtual void runTest();

	virtual void addSQL(string SQLLine);
};

#endif /* BENCHMARKTEST_H_ */
