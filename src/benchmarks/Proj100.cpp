/*
 * Proj100.cpp - Benchmark test class for the proj_100 query
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

#ifndef PROJ100_CPP_
#define PROJ100_CPP_

#include "../BenchmarkTest.h"

string Proj100sql = (string)"select distinct col_address, col_signed from hundred";


class Proj100 : public BenchmarkTest
{
public:
	Proj100(Database& database, Logger& logger) :
		BenchmarkTest("proj_100", Proj100sql, database, logger) {}
	virtual ~Proj100() {}
};

#endif
