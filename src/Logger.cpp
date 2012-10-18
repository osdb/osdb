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

#include "Logger.h"

Logger::Logger()
{
	writeToStdOut = true;
	writeToFile = false;
}

Logger::Logger(string logFileName, bool writeToConsole)
{
	writeToStdOut = writeToConsole;
	initLogFile(logFileName);
}

Logger::~Logger()
{
	if (writeToFile)
		out.close();
}

void Logger::initLogFile(string logFileName)
{
	if (logFileName != "")
	{
		try
		{
			out.open(logFileName.c_str(), ios::app);
		}
		catch (...)
		{
			return;
		}
		writeToFile = true;
	}
}

void Logger::writeMsg(string msg)
{
	if (writeToStdOut)
		cout << msg << endl;
	if (writeToFile)
		out << msg << endl;
}

Logger& Logger::operator <<(string msg)
{
	if (writeToStdOut)
		cout << msg;
	if (writeToFile)
		out << msg;
	return *this;
}

Logger& Logger::operator <<(double msg)
{
	if (writeToStdOut)
		cout << msg;
	if (writeToFile)
		out << msg;
	return *this;
}

Logger& Logger::operator<<(ostream& (*pf) (ostream&))
{
	if (writeToStdOut)
		cout << pf;
	if (writeToFile)
		out << pf;
	return *this;
}

void Logger::writeError(string errorMsg)
{
	if (writeToStdOut)
		cerr << errorMsg << endl;
	if (writeToFile)
		out << errorMsg << endl;
}


