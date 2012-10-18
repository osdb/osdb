/*
 * Join2.cpp - Benchmark test class for the join_2 query
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

#ifndef JOIN2_CPP_
#define JOIN2_CPP_

#include "../BenchmarkTest.h"

string Join2sql = (string)"select uniques.col_signed, uniques.col_name, hundred.col_signed, hundred.col_name "+
	"from uniques, hundred " +
	"where uniques.col_address = hundred.col_address and uniques.col_address = 'SILICON VALLEY'";


class Join2 : public BenchmarkTest
{
public:
	Join2(Database& database, Logger& logger) :
		BenchmarkTest("join_2", Join2sql, database, logger) {}
	virtual ~Join2() {}
};

#endif
