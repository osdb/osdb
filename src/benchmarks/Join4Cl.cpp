/*
 * Join4Cl.cpp - Benchmark test class for the agg_func query
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

#ifndef JOIN4CL_CPP_
#define JOIN4CL_CPP_

#include "../BenchmarkTest.h"

string Join4Clsql = (string)"select uniques.col_date, hundred.col_date, tenpct.col_date, updates.col_date " +
	"from uniques, hundred, tenpct, updates "+
	"where uniques.col_key = hundred.col_key  and uniques.col_key = tenpct.col_key and uniques.col_key = updates.col_key and uniques.col_key = 1000";


class Join4Cl : public BenchmarkTest
{
public:
	Join4Cl(Database& database, Logger& logger) :
		BenchmarkTest("agg_func", Join4Clsql, database, logger) {}
	virtual ~Join4Cl() {}
};

#endif
