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

#include "DataPopulator.h"

DataPopulator::DataPopulator()
{
}

DataPopulator::~DataPopulator()
{
}

void DataPopulator::createTables(Database* dbms)
{
	dbms->createTable("updates","col_key INT NOT NULL, col_int INT NOT NULL, col_signed INT, col_float float4 NOT NULL, col_double float NOT NULL, col_decim numeric(18,2) NOT NULL, col_date char(20) NOT NULL, col_code char(10) NOT NULL, col_name char(20) NOT NULL, col_address varchar(80) NOT NULL");
	dbms->createTable("uniques","col_key INT NOT NULL, col_int INT NOT NULL, col_signed INT, col_float float4 NOT NULL, col_double float NOT NULL, col_decim numeric(18,2) NOT NULL, col_date char(20) NOT NULL, col_code char(10) NOT NULL, col_name char(20) NOT NULL, col_address varchar(80) NOT NULL");
	dbms->createTable("hundred","col_key INT NOT NULL, col_int INT NOT NULL, col_signed INT, col_float float4 NOT NULL, col_double float NOT NULL, col_decim numeric(18,2) NOT NULL, col_date char(20) NOT NULL, col_code char(10) NOT NULL, col_name char(20) NOT NULL, col_address varchar(80) NOT NULL");
	dbms->createTable("tenpct","col_key INT NOT NULL, col_int INT NOT NULL, col_signed INT, col_float float4 NOT NULL, col_double float NOT NULL, col_decim numeric(18,2) NOT NULL, col_date char(20) NOT NULL, col_code char(10) NOT NULL, col_name char(20) NOT NULL, col_address varchar(80) NOT NULL");
	dbms->createTable("tiny","col_key INT NOT NULL, col_int INT NOT NULL, col_signed INT, col_float float4 NOT NULL, col_double float NOT NULL, col_decim numeric(18,2) NOT NULL, col_date char(20) NOT NULL, col_code char(10) NOT NULL, col_name char(20) NOT NULL, col_address varchar(80) NOT NULL");
}

void DataPopulator::loadDataset(Database* dbms)
{
	dbms->loadDataFrom("dataset/asap.updates", "updates");
	dbms->loadDataFrom("dataset/asap.hundred", "hundred");
	dbms->loadDataFrom("dataset/asap.tenpct", "tenpct");
	dbms->loadDataFrom("dataset/asap.uniques", "uniques");
	dbms->loadDataFrom("dataset/asap.tiny", "tiny");
}


