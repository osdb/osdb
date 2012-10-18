/*
 * MuOltpUpdate.cpp - Benchmark test class for the mu_oltp_update query
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

#ifndef MUOLTPUPDATE_CPP_
#define MUOLTPUPDATE_CPP_

#include "../BenchmarkTest.h"

string MuOltpUpdatesql = (string)"update updates " +
		"set col_signed=col_signed+1 " +
		"where col_key=randKey";


class MuOltpUpdate : public BenchmarkTest
{
public:
	MuOltpUpdate(Database& database, Logger& logger) :
		BenchmarkTest("mu_oltp_update", MuOltpUpdatesql, database, logger) {}
	virtual ~MuOltpUpdate() {}
};

#endif
