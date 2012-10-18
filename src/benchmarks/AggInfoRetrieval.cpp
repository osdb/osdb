/*
 * AggInfoRetrieval.cpp - Benchmark test class for the agg_info_retrieval query
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

#ifndef AGGINFORRETREIVAL_CPP_
#define AGGINFORRETREIVAL_CPP_

#include "../BenchmarkTest.h"

string AggInfoRetrievalsql = (string)"select count(col_key) " +
"from tenpct " +
"where col_name = 'THE+ " " +ASAP+ " " +BENCHMARKS+ " " +' and col_int <= 100000000 and col_signed between 1 and 99999999 and not (col_float between -450000000 and 450000000) and col_double > 600000000 and col_decim < -600000000";

class AggInfoRetrieval : public BenchmarkTest
{
public:
	AggInfoRetrieval(Database& database, Logger& logger) :
		BenchmarkTest("agg_info_retrieval", AggInfoRetrievalsql, database, logger) {}
	virtual ~AggInfoRetrieval() {}
};

#endif
