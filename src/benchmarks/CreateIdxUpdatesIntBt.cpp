/*
 * CreateIdxUpdatesIntBt.cpp - Benchmark test class for the create_idx_updates_int_bt query
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

#ifndef CREATEIDXUPDATESINTBT_CPP_
#define CREATEIDXUPDATESINTBT_CPP_

#include "../BenchmarkTest.h"

string CreateIdxUpdatesIntBtsql = (string)"create index updates_int_bt on updates BTREE(col_int)";


class CreateIdxUpdatesIntBt : public BenchmarkTest
{
public:
	CreateIdxUpdatesIntBt(Database& database, Logger& logger) :
		BenchmarkTest("create_idx_updates_int_bt", CreateIdxUpdatesIntBtsql, database, logger) {}
	virtual ~CreateIdxUpdatesIntBt() {}
};

#endif
