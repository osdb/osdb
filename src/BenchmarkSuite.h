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

#ifndef BENCHMARKSUITE_H_
#define BENCHMARKSUITE_H_

#include <string>
#include <vector>
#include "BenchmarkTest.h"

using namespace std;

class BenchmarkSuite: public Benchmark
{
private:
	vector<BenchmarkTest*> benchmarks;
public:
	BenchmarkSuite(Database&, Logger&);
	BenchmarkSuite(string, Database&, Logger&);
	BenchmarkSuite(string, vector<BenchmarkTest*>&, Database& database, Logger& logger);

	virtual ~BenchmarkSuite();
	virtual void addTest(BenchmarkTest*);
	virtual void runTest();
	string getSuiteName();
	vector<BenchmarkTest*> getTestsInSuite();
};

#endif /* BENCHMARKSUITE_H_ */
