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
#ifndef OSDB_H_
#define OSDB_H_

#include <vector>
#include "BenchmarkMode.h"
#include "Configuration.h"
#include "dbms/MySQLDB.h"
#include "Logger.h"
#include "Timer.h"
#include "DataPopulator.h"

using namespace std;

class OSDB
{
private:
	vector<BenchmarkMode*> modes;
	Configuration *config;
	Database *dbms;
	Logger *logger;
	DataPopulator populator;
public:
	OSDB();
	OSDB(int argc, char** argv);
	virtual ~OSDB();
	void init(int argc, char** argv);
	void loadConfig(int argc, char** argv);
	void loadDBModule();
	void loadModes();
	void runBenchmarks();
};

#endif /* OSDB_H_ */
