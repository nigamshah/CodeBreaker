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
#include "JsonObject.h"
#include "StringUtils.h"

using namespace cocos2d;
using namespace cocos2d::extension;
using namespace std;

namespace codebreaker {

	class Config {

	private:
		const char* const FILENAME_SETTINGS_GLOBAL = "settings_global.json";
		JsonObject* _globalConfig;

	public:
		~Config() {
			CC_SAFE_RELEASE(_globalConfig);
		}

		bool init() {
			string fileContentsGlobal = FileReader::FileReaderText(FILENAME_SETTINGS_GLOBAL);
			CCLog("contents of file = \n%s", fileContentsGlobal.c_str());
			if (fileContentsGlobal.empty()) return false;

			Json* jsonNode = Json_create(fileContentsGlobal.c_str());
			_globalConfig = JsonObject::create();
			_globalConfig->retain();
			_globalConfig->setJsonNode(jsonNode);

			return true;
		}

		JsonObject* getJsonObject(string keyPath) {
			JsonObject* result = _globalConfig->getChild(keyPath);
			return result;
		}
	};
}


#endif /* defined(__CodeBreaker__Config__) */
