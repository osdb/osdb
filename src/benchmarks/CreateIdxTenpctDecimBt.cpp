/*
 * CreateIdxTenpctDecimBt.cpp - Benchmark test class for the create_idx_tenpct_decim_bt query
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

#ifndef CREATEIDXTENPCTDECIMBT_CPP_
#define CREATEIDXTENPCTDECIMBT_CPP_

#include "../BenchmarkTest.h"

string CreateIdxTenpctDecimBtsql = (string)"create index tenpct_decim_bt on tenpct BTREE(col_decim)";


class CreateIdxTenpctDecimBt : public BenchmarkTest
{
public:
	CreateIdxTenpctDecimBt(Database& database, Logger& logger) :
		BenchmarkTest("create_idx_tenpct_decim_bt", CreateIdxTenpctDecimBtsql, database, logger) {}
	virtual ~CreateIdxTenpctDecimBt() {}
};

#endif
