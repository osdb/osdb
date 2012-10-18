/*
 * UpdRemoveDuplicate.cpp - Benchmark test class for the upd_remove_duplicate query
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

#ifndef UPDREMOVEDUPLICATE_CPP_
#define UPDREMOVEDUPLICATE_CPP_

#include "../BenchmarkTest.h"

string UpdRemoveDuplicatesql = (string)"delete from updates where col_key = 6000 and col_int = 0";


class UpdRemoveDuplicate : public BenchmarkTest
{
public:
	UpdRemoveDuplicate(Database& database, Logger& logger) :
		BenchmarkTest("upd_remove_duplicate", UpdRemoveDuplicatesql, database, logger) {}
	virtual ~UpdRemoveDuplicate() {}
};

#endif
