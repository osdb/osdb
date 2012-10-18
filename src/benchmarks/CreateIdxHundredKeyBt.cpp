/*
 * CreateIdxHundredKeyBt.cpp - Benchmark test class for the create_idx_hundred_key_bt query
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

#ifndef CREATEIDXHUNDREDKEYBT_CPP_
#define CREATEIDXHUNDREDKEYBT_CPP_

#include "../BenchmarkTest.h"

string CreateIdxHundredKeyBtsql = (string)"create unique index hundred_key_bt on hundred BTREE(col_key)";

class CreateIdxHundredKeyBt : public BenchmarkTest
{
public:
	CreateIdxHundredKeyBt(Database& database, Logger& logger) :
		BenchmarkTest("create_idx_hundred_key_bt", CreateIdxHundredKeyBtsql, database, logger) {}
	virtual ~CreateIdxHundredKeyBt() {}
};

#endif
