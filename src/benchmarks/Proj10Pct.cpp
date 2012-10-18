/*
 * Proj10Pct.cpp - Benchmark test class for the proj_10_pct query
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

#ifndef PROJ10PCT_CPP_
#define PROJ10PCT_CPP_

#include "../BenchmarkTest.h"

string Proj10Pctsql = (string)"select distinct col_signed from tenpct";


class Proj10Pct : public BenchmarkTest
{
public:
	Proj10Pct(Database& database, Logger& logger) :
		BenchmarkTest("proj_10_pct", Proj10Pctsql, database, logger) {}
	virtual ~Proj10Pct() {}
};

#endif
