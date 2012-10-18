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

#ifndef MYSQLDB_H_
#define MYSQLDB_H_

#include <mysql/mysql.h>
#include "Database.h"
#include <stdio.h>
#include <stdlib.h>

class MySQLDB: public Database {
public:
	MySQLDB(Configuration&);
	MySQLDB(Configuration&, string, string, string, string);
	virtual ~MySQLDB();

	virtual void connect();
	virtual void disconnect();
	virtual int countTuples();
	virtual void createDB(string dbName);
	virtual void dropDB(string dbName);
	virtual void selectDB(string db);
	virtual void createTable(string tableName, string tableStructure);
	virtual void dropTable(string tableName);
	virtual void execute(string query);
	virtual void loadDataFrom(string filename, string tablename);
	virtual void beginTransaction();
	virtual void endTransaction();
	virtual void generateConfig();

private:
	string server;
	string user;
	string password;
	string dbname;

	MYSQL *conn;
	MYSQL_RES *res_set;
};

#endif /* MYSQLDB_H_ */
