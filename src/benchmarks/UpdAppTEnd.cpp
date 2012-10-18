/*
 * UpdAppTEnd.cpp - Benchmark test class for the upd_app_t_end query
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

#ifndef UPDAPPTEND_CPP_
#define UPDAPPTEND_CPP_

#include "../BenchmarkTest.h"

string UpdAppTEndsql = (string)"insert into updates " +
		"values (1000000001, 50005, 50005, 50005.00, 50005.00, 50005.00, '1/1/1988', 'CONTROLLER', 'ALICE IN WONDERLAND',  'UNIVERSITY OF ILLINOIS AT CHICAGO')";


class UpdAppTEnd : public BenchmarkTest
{
public:
	UpdAppTEnd(Database& database, Logger& logger) :
		BenchmarkTest("upd_app_t_end", UpdAppTEndsql, database, logger) {}
	virtual ~UpdAppTEnd() {}
};

#endif
