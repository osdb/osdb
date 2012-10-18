/*
 * AggFunc.cpp - Benchmark test class for the agg_func query
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

#ifndef AGGFUNC_CPP_
#define AGGFUNC_CPP_

#include "../BenchmarkTest.h"

string AggFuncsql = (string)"select min(col_key) " +
"from hundred " +
"group by col_name";

class AggFunc : public BenchmarkTest
{
public:
	AggFunc(Database& database, Logger& logger) :
		BenchmarkTest("agg_func", AggFuncsql, database, logger) {}
	virtual ~AggFunc() {}
};

#endif
