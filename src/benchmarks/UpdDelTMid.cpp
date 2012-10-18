/*
 * UpdDelTMid.cpp - Benchmark test class for the upd_del_t_mid query
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

#ifndef UPDDELTMID_CPP_
#define UPDDELTMID_CPP_

#include "../BenchmarkTest.h"

string UpdDelTMidsql = (string)"delete from updates where (col_key='5005') or (col_key='-5000')";


class UpdDelTMid : public BenchmarkTest
{
public:
	UpdDelTMid(Database& database, Logger& logger) :
		BenchmarkTest("upd_del_t_mid", UpdDelTMidsql, database, logger) {}
	virtual ~UpdDelTMid() {}
};

#endif
