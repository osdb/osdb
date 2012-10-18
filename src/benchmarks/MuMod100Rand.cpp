/*
 * MuMod100Rand.cpp - Benchmark test class for the mu_mod_100_rand query
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

#ifndef MUMOD100RAND_CPP_
#define MUMOD100RAND_CPP_

#include "../BenchmarkTest.h"

string MuMod100Randsql = (string)"update updates " +
		"set col_double = col_double+100000000 " +
		"where col_int between 1001 and 1100";


class MuMod100Rand : public BenchmarkTest
{
public:
	MuMod100Rand(Database& database, Logger& logger) :
		BenchmarkTest("mu_mod_100_rand", MuMod100Randsql, database, logger) {}
	virtual ~MuMod100Rand() {}
};

#endif
