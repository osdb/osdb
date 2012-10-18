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

#include "Database.h"

Database::Database(Configuration& configuration) : config(configuration)
{
}

Database::~Database()
{
}

void Database::connect()
{
}



void Database::createDB(string dbName)
{
}



void Database::createTable(string tableName, string tableStructure)
{
}



int Database::countTuples()
{
}



void Database::disconnect()
{
}



void Database::execute(string query)
{
}



void Database::dropDB(string dbName)
{
}



void Database::dropTable(string tableName)
{
}

void Database::selectDB(string dbName) {
}

void Database::loadDataFrom(string filename, string tablename)
{
}

void Database::beginTransaction()
{
}

void Database::endTransaction()
{
}

void Database::generateConfig()
{

}
