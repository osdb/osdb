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

#include "Configuration.h"
#include "Database.h"

Configuration::Configuration(string configFile)
{
	if (!configs.LoadFile(configFile))
	{
		generateConfig();
	}
}

Configuration::~Configuration()
{
	saveConfig();
}

string Configuration::getConfigSetting(string sectionName, string settingName)
{
	string returnval = "";
	TiXmlElement* setting = findConfigSetting(sectionName, settingName);
	if (setting)
	{
		returnval = setting->GetText();
	}
	return returnval;
}

TiXmlElement* Configuration::findConfigSetting(string sectionName, string settingName)
{
	TiXmlHandle docHandle(&configs);
	return docHandle.FirstChild("osdb").FirstChild(sectionName).FirstChild(settingName).ToElement();
}

bool Configuration::settingExists(string sectionName, string settingName)
{
	if (findConfigSetting(sectionName, settingName))
		return true;
	else
		return false;
}

void Configuration::setConfigSetting(string sectionName, string settingName, string settingValue)
{
	TiXmlElement* setting = findConfigSetting(sectionName, settingName);
	if (setting)
	{
		TiXmlText* settingText = setting->ToText();
		if (settingText)
			settingText->SetValue(settingValue);
	}
	else
	{
		// Check to see if the section exists
		TiXmlHandle docHandle(&configs);
		TiXmlElement* newSection = docHandle.FirstChild("osdb").FirstChild(sectionName).ToElement();
		if (!newSection)
		{
			newSection = new TiXmlElement(sectionName);
			configs.RootElement()->LinkEndChild(newSection);
		}

		TiXmlElement* newSettingElement = new TiXmlElement(settingName);
		newSettingElement->LinkEndChild(new TiXmlText(settingValue));
		newSection->LinkEndChild(newSettingElement);
	}

	saveConfig();
}

/*
 * Generates setting placeholders for any missing sections
 * ** Plugins should verify that their settings exist and
 * ** create new placeholders if they do not exist!
 */
void Configuration::generateConfig()
{
	TiXmlDeclaration* decl = new TiXmlDeclaration("1.0", "", "");
	configs.LinkEndChild(decl);

	TiXmlElement* root = new TiXmlElement("osdb");
	configs.LinkEndChild(root);

	TiXmlComment* comment = new TiXmlComment();
	comment->SetValue(" Settings for OSDB ");
	root->LinkEndChild(comment);

	setConfigSetting("main", "logFilePath", "osdb.log");
	setConfigSetting("main", "useStdOut", "true");
}

void Configuration::saveConfig()
{
	configs.SaveFile();
}
