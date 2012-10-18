/*
 * UpdModTEnd.cpp - Benchmark test class for the upd_mod_t_end query
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

#ifndef UPDMODTEND_CPP_
#define UPDMODTEND_CPP_

#include "../BenchmarkTest.h"

string UpdModTEndsql = (string)"update updates set col_key = '-1000' where col_key = 1000000001";


class UpdModTEnd : public BenchmarkTest
{
public:
	UpdModTEnd(Database& database, Logger& logger) :
		BenchmarkTest("upd_mod_t_end", UpdModTEndsql, database, logger) {}
	virtual ~UpdModTEnd() {}
};

#endif
