/*
 * AggCreateView.cpp - Benchmark test class for the agg_create_view query
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

#ifndef AGGCREATEVIEW_CPP_
#define AGGCREATEVIEW_CPP_

#include "../BenchmarkTest.h"

string AggCreateViewsql = (string)"create view reportview(col_key,col_signed,col_date,col_decim,col_name,col_code,col_int) as " +
"select updates.col_key, updates.col_signed, updates.col_date, updates.col_decim, hundred.col_name, hundred.col_code, hundred.col_int " +
"from updates, hundred " +
"where updates.col_key = hundred.col_key";

class AggCreateView : public BenchmarkTest
{
public:
	AggCreateView(Database& database, Logger& logger) :
		BenchmarkTest("agg_create_view", AggCreateViewsql, database, logger) {}
	virtual ~AggCreateView() {}
};

#endif
