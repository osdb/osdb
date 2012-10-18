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

#ifndef SINGLEUSERMODE_H_
#define SINGLEUSERMODE_H_

#include <string>
#include "BenchmarkMode.h"
#include "BenchmarkSuite.h"

using namespace std;

class AS3APSuite;

class SingleUserMode: public BenchmarkMode {
private:
	string modeName;
	Timer testTimer;
	Logger& log;
	Database& db;
	AS3APSuite* as3apSuite;

public:
	SingleUserMode(Database& , Logger&);
	virtual ~SingleUserMode();
	void runScenario();
	void loadTests();
};

#endif /* SINGLEUSERMODE_H_ */
