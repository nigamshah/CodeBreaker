//
//  Tester.h
//  CodeBreaker
//
//  Created by Nigam Shah on 8/13/13.
//
//

#ifndef __CodeBreaker__Tester__
#define __CodeBreaker__Tester__

#include "FileReader.h"
#include "Json.h"
#include "Config.h"


namespace codebreaker {
	using namespace cocos2d::extension;

	class Tester {
		
	public:

		void init() {
			std::string fileContentsGlobal = FileReader::FileReaderText("settings_global.json");
			CCLog("contents of file = \n%s", fileContentsGlobal.c_str());

			Json* json = Json_create(fileContentsGlobal.c_str());

			Json* titleNode = Json_getItem(json, "game_title");

			const char* titleStr = Json_getString(json, "game_title", "No Value");
			CCLog("titleStr = %s", titleStr);
			


//Json* Json_create (const char* value);


		}

	};
}
#endif /* defined(__CodeBreaker__Tester__) */
