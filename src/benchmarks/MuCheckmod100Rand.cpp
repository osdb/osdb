/*
 * MuCheckmod100Rand.cpp - Benchmark test class for the mu_checkmod_100_rand query
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

#ifndef MUCHECKMOD100RAND_CPP_
#define MUCHECKMOD100RAND_CPP_

#include "../BenchmarkTest.h"

string MuCheckmod100Randsql = (string)"select count(*) " +
	"from updates, sel100rand " +
	"where updates.col_key=sel100rand.col_key and not (updates.col_double=sel100rand.col_double)";


class MuCheckmod100Rand : public BenchmarkTest
{
public:
	MuCheckmod100Rand(Database& database, Logger& logger) :
		BenchmarkTest("mu_checkmod_100_rand", MuCheckmod100Randsql, database, logger) {}
	virtual ~MuCheckmod100Rand() {}
};

#endif
