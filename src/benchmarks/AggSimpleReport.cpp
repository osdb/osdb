/*
 * AggSimpleReport.cpp - Benchmark test class for the agg_simple_report query
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

#ifndef AGGSIMPLEREPORT_CPP_
#define AGGSIMPLEREPORT_CPP_

#include "../BenchmarkTest.h"

string AggSimpleReportsql = (string)"select avg(updates.col_decim) " +
		"from updates " +
		"where updates.col_key in " +
			"(select updates.col_key " +
			"from updates, hundred " +
			"where hundred.col_key = updates.col_key and updates.col_decim > 980000000)";


class AggSimpleReport : public BenchmarkTest
{
public:
	AggSimpleReport(Database& database, Logger& logger) :
		BenchmarkTest("agg_simple_report", AggSimpleReportsql, database, logger) {}
	virtual ~AggSimpleReport() {}
};

#endif
