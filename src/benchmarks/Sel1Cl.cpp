/*
 * Sel1Cl.cpp - Benchmark test class for the sel_1_cl query
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

#ifndef SEL1CL_CPP_
#define SEL1CL_CPP_

#include "../BenchmarkTest.h"

string Sel1Clsql = (string)"select col_key, col_int, col_signed, col_code, col_double, col_name " +
		"from updates " +
		"where col_key = 1000";

class Sel1Cl : public BenchmarkTest
{
public:
	Sel1Cl(Database& database, Logger& logger) :
		BenchmarkTest("sel_1_cl", Sel1Clsql, database, logger) {}
	virtual ~Sel1Cl() {}
};

#endif
