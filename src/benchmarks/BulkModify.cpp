/*
 * BulkModify.cpp - Benchmark test class for the bulk_modify query
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

#ifndef BULKMODIFY_CPP_
#define BULKMODIFY_CPP_

#include "../BenchmarkTest.h"

string BulkModifysql = (string)"update updates " +
					"set col_key = col_key - 100000 " +
					"where col_key between 5000 and 5999";


class BulkModify : public BenchmarkTest
{
public:
	BulkModify(Database& database, Logger& logger) :
		BenchmarkTest("bulk_modify", BulkModifysql, database, logger) {}
	virtual ~BulkModify() {}
};

#endif
