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

#ifndef BENCHMARK_H_
#define BENCHMARK_H_

#include <string>
#include <map>
#include "Logger.h"
#include "Database.h"
#include "Timer.h"

using namespace std;

class Benchmark
{
protected:
	string name;
	Timer timer;
	Database& db;
	Logger& log;
public:
	Benchmark(Database& database, Logger& logger);
	Benchmark(string name, Database& database, Logger& logger);
	virtual ~Benchmark();
	virtual void runTest() = 0;
	virtual string getName();
	template<typename T>void registerBenchmark();
};

#endif /* BENCHMARK_H_ */
