/*
 * AggCreateView.cpp - Benchmark test class for the agg_create_view query
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

#ifndef AGGTOTALREPORT_CPP_
#define AGGTOTALREPORT_CPP_

#include "../BenchmarkTest.h"

string AggTotalReportsql = (string)"select avg(col_signed), min(col_signed), max(col_signed), max(col_date), min(col_date), count(distinct col_name), count(col_name), count(col_code), count(col_int) " +
		"from reportview " +
		"where col_decim > 980000000";
 

class AggTotalReport : public BenchmarkTest
{
public:
	AggTotalReport(Database& database, Logger& logger) :
		BenchmarkTest("agg_total_report", AggTotalReportsql, database, logger) {}
	virtual ~AggTotalReport() {}
};

#endif
