/*
 * CreateIdxTenpctIntBt.cpp - Benchmark test class for the create_idx_tenpct_int_bt query
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

#ifndef CREATEINDTENPCTINTBT_CPP_
#define CREATEINDTENPCTINTBT_CPP_

#include "../BenchmarkTest.h"

string CreateIdxTenpctIntBtsql = (string)"create index tenpct_int_bt on tenpct BTREE(col_int)";


class CreateIdxTenpctIntBt : public BenchmarkTest
{
public:
	CreateIdxTenpctIntBt(Database& database, Logger& logger) :
		BenchmarkTest("create_idx_tenpct_int_bt", CreateIdxTenpctIntBtsql, database, logger) {}
	virtual ~CreateIdxTenpctIntBt() {}
};

#endif
