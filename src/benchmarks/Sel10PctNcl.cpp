/*
 * Sel10PctNcl.cpp - Benchmark test class for the sel_10pct_ncl query
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

#ifndef SEL10PCTNCL_CPP_
#define SEL10PCTNCL_CPP_

#include "../BenchmarkTest.h"

string Sel10PctNclsql = (string)"select col_key, col_int, col_signed, col_code, col_double, col_name " +
		"from tenpct " +
		"where col_name = 'THE+ " " +ASAP+ " " +BENCHMARKS+ " " +'";

class Sel10PctNcl : public BenchmarkTest
{
public:
	Sel10PctNcl(Database& database, Logger& logger) :
		BenchmarkTest("sel_10pct_ncl", Sel10PctNclsql, database, logger) {}
	virtual ~Sel10PctNcl() {}
};

#endif
