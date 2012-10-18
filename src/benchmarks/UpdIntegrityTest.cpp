/*
 * UpdIntegrityTest.cpp - Benchmark test class for the upd_integrity_test query
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

#ifndef UPDINTEGRITYTEST_CPP_
#define UPDINTEGRITYTEST_CPP_

#include "../BenchmarkTest.h"

string UpdIntegrityTestsql = (string)"update hundred set col_signed = '-500000000' where col_int = 0";


class UpdIntegrityTest : public BenchmarkTest
{
public:
	UpdIntegrityTest(Database& database, Logger& logger) :
		BenchmarkTest("upd_integrity_test", UpdIntegrityTestsql, database, logger) {}
	virtual ~UpdIntegrityTest() {}
};

#endif
