//
//  Config.cpp
//  CodeBreaker
//
//  Created by Nigam Shah on 8/13/13.
//
//

#include "Config.h"
#include "FileReader.h"
#include "Json.h"

using namespace cocos2d::extension::Json
using namespace codebreaker;

bool Config::init() {

	string fileContentsGlobal = FileReader::FileReaderText(FILENAME_SETTINGS_GLOBAL);
	CCLog("contents of file = \n%s", fileContentsGlobal.c_str());
	if (fileContentsGlobal.empty()) return false;

	Json* json = Json_create(fileContentsGlobal.c_str());

	Json* titleNode = Json_getItem(json, "game_title");

	const char* titleStr = Json_getString(json, "game_title", "No Value");
	CCLog("titleStr = %s", titleStr);

	return true;
}