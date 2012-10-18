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

#include "MySQLDB.h"
#include <iostream>

MySQLDB::MySQLDB(Configuration& configuration) :
	Database(configuration)
{
	server = config.getConfigSetting("mysql", "server");
	if (server == "")
		generateConfig();
	user = config.getConfigSetting("mysql", "user");
	password = config.getConfigSetting("mysql", "password");
	dbname = config.getConfigSetting("mysql", "database");
}

MySQLDB::MySQLDB(Configuration& configuration, string server, string user, string password, string dbname) :
	Database(config)
{
	this->server = server;
	this->user = user;
	this->password = password;
	this->dbname = dbname;
}

MySQLDB::~MySQLDB()
{
	if (conn)
	{
		dropDB(dbname);
		disconnect();
	}
}

void MySQLDB::connect()
{
	conn = mysql_init(NULL);

	/* Connect to database */
	if (!mysql_real_connect(conn, server.c_str(), user.c_str(), password.c_str(), "", 0, NULL, 0))
	{
		cerr << mysql_error(conn) << endl;
		exit(1);
	}

	createDB(dbname);
	selectDB(dbname);

	mysql_autocommit(conn, 0);
}

void MySQLDB::createDB(string dbName)
{
	// creates the db using CREATE DATABASE SQL
	execute("CREATE DATABASE IF NOT EXISTS " + dbName);
}

void MySQLDB::createTable(string tableName, string tableStructure)
{
	// create the table using CREATE TABLE SQL
	execute("CREATE TABLE IF NOT EXISTS " + tableName + "(" + tableStructure + ")");
}

int MySQLDB::countTuples()
{
	my_ulonglong num_rows;

	const char* query = "Select * From *";

	// TODO: are we counting TOTAL tuples in the db schema?
	mysql_query(conn, query);
	res_set = mysql_store_result(conn);

	num_rows = mysql_num_rows(res_set);

	return (int) num_rows;
}

void MySQLDB::disconnect()
{
	// disconnect from server
	mysql_close(conn);

	//	if (!mysql_close(conn)) {
	//		   fprintf(stderr, "%s\n", mysql_error(conn));
	//		   exit(1);
	//	}
	conn = NULL;
}

void MySQLDB::execute(string query)
{
	// TODO: return type boolean?

	if (mysql_query(conn, query.c_str()) != 0)
	{
		cerr << "mysql_query() failed " << mysql_error(conn) << endl;
	}
	else
	{
		res_set = mysql_store_result(conn);

		/* generate a result set */
		if (res_set == NULL)
		{ /* No result set returned */
			if (mysql_field_count(conn) == 0)
			{
				/* query executed correctly, but no rows were returned */
				//				printf("%lu rows affected\n", (unsigned long) mysql_affected_rows(conn));
			}
			else
			{
				/* query executed correctly, but no rows were returned */
				cerr << "mysql_store_result() failed, could not retrieve result set " << mysql_error(conn) << endl;
			}
		}
		else
		{ /* result set returned, process then deallocate */
			//process_result_set (conn, res_set);
			mysql_free_result(res_set);
		}
	}
}

void process_result_set(MYSQL *conn, MYSQL_RES *res_set)
{
	MYSQL_ROW row;

	while ((row = mysql_fetch_row(res_set)) != NULL)
	{
		//TODO: What do we do with our result set?
	}
}

void MySQLDB::dropDB(string dbName)
{
	// drops the database, DROP DATABASE SQL will return # of tables deleted
	execute("DROP DATABASE IF EXISTS " + dbName);
}

void MySQLDB::dropTable(string tableName)
{
	// drops the table using SQL
	execute("DROP TABLE IF EXISTS " + tableName);
}

void MySQLDB::selectDB(string dbName)
{
	// switches the current database to dbName
	mysql_select_db(conn, dbName.c_str());
}

void MySQLDB::loadDataFrom(string filename, string tablename)
{
	execute((string) "load data local infile '" + filename + "' into table " + tablename + " fields terminated by ','");
}

void MySQLDB::beginTransaction()
{
}

void MySQLDB::endTransaction()
{
	if (mysql_commit(conn))
	{
		cerr << "mysql_commit() failed " << mysql_error(conn) << endl;
		if (mysql_rollback(conn))
			cerr << "mysql_rollback() also failed " << mysql_error(conn) << endl;
	}
}

void MySQLDB::generateConfig()
{
	if (!config.settingExists("mysql", "server"))
		config.setConfigSetting("mysql", "server", "localhost");
	if (!config.settingExists("mysql", "user"))
		config.setConfigSetting("mysql", "user", "osdb");
	if (!config.settingExists("mysql", "password"))
		config.setConfigSetting("mysql", "password", "osdb");
	if (!config.settingExists("mysql", "dbname"))
		config.setConfigSetting("mysql", "dbname", "osdb");
	cerr << "Need to configure the settings file for MySQL - aborting" << endl;
	exit(0);
}
