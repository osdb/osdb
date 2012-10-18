/*
 * Join3Ncl.cpp - Benchmark test class for the join_3_ncl query
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

#ifndef JOIN3NCL_CPP_
#define JOIN3NCL_CPP_

#include "../BenchmarkTest.h"

string Join3Nclsql = (string)"select uniques.col_signed, uniques.col_date, hundred.col_signed, hundred.col_date, tenpct.col_signed, tenpct.col_date " +
		"from uniques, hundred, tenpct " +
		"where uniques.col_code = hundred.col_code and uniques.col_code = tenpct.col_code and uniques.col_code = 'BENCHMARKS'";

class Join3Ncl : public BenchmarkTest
{
public:
	Join3Ncl(Database& database, Logger& logger) :
		BenchmarkTest("join_3_ncl", Join3Nclsql, database, logger) {}
	virtual ~Join3Ncl() {}
};

#endif
