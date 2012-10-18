/*
 * CreateIdxUniquesKeyBt.cpp - Benchmark test class for the create_idx_uniques_key_bt query
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

#ifndef CREATEIDXUNIQUESKEYBT_CPP_
#define CREATEIDXUNIQUESKEYBT_CPP_

#include "../BenchmarkTest.h"

string CreateIdxUniquesKeyBtsql = (string)"create unique index uniques_key_bt on uniques BTREE(col_key)";


class CreateIdxUniquesKeyBt : public BenchmarkTest
{
public:
	CreateIdxUniquesKeyBt(Database& database, Logger& logger) :
		BenchmarkTest("create_idx_uniques_key_bt", CreateIdxUniquesKeyBtsql, database, logger) {}
	virtual ~CreateIdxUniquesKeyBt() {}
};

#endif
