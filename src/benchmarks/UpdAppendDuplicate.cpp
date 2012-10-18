/*
 * UpdAppendDuplicate.cpp - Benchmark test class for the upd_append_duplicate query
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

#ifndef UPDAPPENDDUPLICATE_CPP_
#define UPDAPPENDDUPLICATE_CPP_

#include "../BenchmarkTest.h"

string UpdAppendDuplicatesql = (string)"insert into updates  (col_key, col_int, col_signed, col_float,col_double, col_decim, col_date, col_code, col_name, col_address) " +
	"values( 6000, 0, 60000, 39997.90, 50005.00, 50005.00,  '11/10/1985', 'CONTROLLER', 'ALICE IN WONDERLAND',  'UNIVERSITY OF ILLINOIS AT CHICAGO')";


class UpdAppendDuplicate : public BenchmarkTest
{
public:
	UpdAppendDuplicate(Database& database, Logger& logger) :
		BenchmarkTest("upd_append_duplicate", UpdAppendDuplicatesql, database, logger) {}
	virtual ~UpdAppendDuplicate() {}
};

#endif
