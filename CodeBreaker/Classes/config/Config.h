//
//  Config.h
//  CodeBreaker
//
//  Created by Nigam Shah on 8/13/13.
//
//

#ifndef __CodeBreaker__Config__
#define __CodeBreaker__Config__
#include "Config.h"
#include "FileReader.h"
#include "Json.h"
#include "StringUtils.h"

using namespace cocos2d::extension;
using namespace std;

namespace codebreaker {

	class Config {

	private:
		const char* const FILENAME_SETTINGS_GLOBAL = "settings_global.json";
		Json* _globalConfig;

	public:

		bool init() {
			string fileContentsGlobal = FileReader::FileReaderText(FILENAME_SETTINGS_GLOBAL);
			CCLog("contents of file = \n%s", fileContentsGlobal.c_str());
			if (fileContentsGlobal.empty()) return false;

			_globalConfig = Json_create(fileContentsGlobal.c_str());
			Json* titleNode = Json_getItem(_globalConfig, "game_title");
			const char* titleStr = Json_getString(_globalConfig, "game_title", "No Value");
			CCLog("titleStr = %s", titleStr);

			Json* jsonObj1 = getJsonObject("entity_templates");
			Json* jsonObj = getJsonObject("entity_templates.board.board_factory.grid_size");


			return true;
		}

		Json* getJsonObject(string keyPath) {
			Json* result = _globalConfig;
			vector<string> keyVector = StringUtils::split(keyPath, '.');

			for(string key : keyVector) {
				result = Json_getItem(result, key.c_str());
			}

			return result;
		}
	};
}


#endif /* defined(__CodeBreaker__Config__) */
