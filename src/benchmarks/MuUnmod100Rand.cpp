/*
 * MuUnmod100Rand.cpp - Benchmark test class for the mu_unmod_100_rand query
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

#ifndef MUUNMOD100RAND_CPP_
#define MUUNMOD100RAND_CPP_

#include "../BenchmarkTest.h"

string MuUnmod100Randsql = (string)"select min(col_key) " +
		"from hundred " +
		"group by col_name";


class MuUnmod100Rand : public BenchmarkTest
{
public:
	MuUnmod100Rand(Database& database, Logger& logger) :
		BenchmarkTest("mu_unmod_100_rand", MuUnmod100Randsql, database, logger) {}
	virtual ~MuUnmod100Rand() {}
};

#endif
