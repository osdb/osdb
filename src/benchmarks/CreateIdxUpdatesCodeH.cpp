/*
 * CreateIdxUpdatesCodeH.cpp - Benchmark test class for the create_idx_updates_code_h query
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

#ifndef CREATEIDXUPDATESCODEH_CPP_
#define CREATEIDXUPDATESCODEH_CPP_

#include "../BenchmarkTest.h"

string CreateIdxUpdatesCodeHsql = (string)"create index updates_code_h on updates HASH(col_code)";


class CreateIdxUpdatesCodeH : public BenchmarkTest
{
public:
	CreateIdxUpdatesCodeH(Database& database, Logger& logger) :
		BenchmarkTest("create_idx_updates_code_h", CreateIdxUpdatesCodeHsql, database, logger) {}
	virtual ~CreateIdxUpdatesCodeH() {}
};

#endif
