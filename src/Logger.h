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

#ifndef LOGGER_H_
#define LOGGER_H_

#include <string>
#include <iostream>
#include <fstream>
#include <ostream>

using namespace std;

class Logger
{
private:
	bool writeToStdOut;
	bool writeToFile;
	ofstream out;
public:
	Logger();
	Logger(string logFileName, bool writeToConsole);
	virtual ~Logger();
	void initLogFile(string logFileName);
	void writeMsg(string msg);
	Logger& operator<<(string msg);
	Logger& operator<<(double msg);
	Logger& operator<<(ostream& (*pf) (ostream&));
	void writeError(string errorMsg);
};

#endif /* LOGGER_H_ */
