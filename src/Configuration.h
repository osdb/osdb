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

#ifndef CONFIGURATION_H_
#define CONFIGURATION_H_

#include <string>
//#include <vector>
#include "tinyxml.h"

using namespace std;

class Database;

class Configuration
{
private:
	TiXmlDocument configs;
	TiXmlElement* findConfigSetting(string sectionName, string settingName);
public:
	Configuration(string configFile);
	virtual ~Configuration();
	string getConfigSetting(string sectionName, string settingName);
	bool settingExists(string sectionName, string settingName);
	void setConfigSetting(string sectionName, string settingName, string settingValue);
//	vector<string> getConfigSettings(string sectionName, string settingName);
//	void setConfigSettings(string sectionName, string settingName, vector<string> settingValues);
	void generateConfig();
	void saveConfig();
};

#endif /* CONFIGURATION_H_ */
