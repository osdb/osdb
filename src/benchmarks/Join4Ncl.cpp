/*
 * Join4Ncl.cpp - Benchmark test class for the join_4_ncl query
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

#ifndef JOIN4NCL_CPP_
#define JOIN4NCL_CPP_

#include "../BenchmarkTest.h"

string Join4Nclsql = (string)"select uniques.col_date, hundred.col_date, tenpct.col_date, updates.col_date " +
	"from uniques, hundred, tenpct, updates " +
	"where uniques.col_code = hundred.col_code and uniques.col_code = tenpct.col_code and uniques.col_code = updates.col_code and uniques.col_code = 'BENCHMARKS'";


class Join4Ncl : public BenchmarkTest
{
public:
	Join4Ncl(Database& database, Logger& logger) :
		BenchmarkTest("join_4_ncl", Join4Nclsql, database, logger) {}
	virtual ~Join4Ncl() {}
};

#endif
