//
//  JsonObject.h
//  CodeBreaker
//
//  Created by Nigam Shah on 8/14/13.
//
//

#ifndef __CodeBreaker__JsonObject__
#define __CodeBreaker__JsonObject__

#include "cocos2d.h"
#include "StringUtils.h"
#include "Json.h"

using namespace cocos2d;
using namespace cocos2d::extension;
using namespace std;

namespace codebreaker {

	/*
	//	#define Json_False 0
	//	#define Json_True 1
	//	#define Json_NULL 2
	//	#define Json_Number 3
	//	#define Json_String 4
	//	#define Json_Array 5
	//	#define Json_Object 6
	*/
	
	class JsonObject : public CCObject {

	private:

		Json* _getChildNode(string keyPath) {
			Json* result = _jsonNode;
			vector<string> keyVector = StringUtils::split(keyPath, '.');

			for(string key : keyVector) {
				result = Json_getItem(result, key.c_str());
				if (!result) {
					CCLOGERROR("Error! Bad Json query for: %s", keyPath.c_str());
				}
			}

			return result;
		}

	public:
		CC_SYNTHESIZE(Json*, _jsonNode, JsonNode);
		CREATE_FUNC(JsonObject);

		bool init() { return true; }

		JsonObject* getChild(string keyPath) {
			Json* targetNode = _getChildNode(keyPath);
			JsonObject* result = JsonObject::create();
			result->setJsonNode(targetNode);
			return result;
		}

		// only if the jsonNode is a json array
		JsonObject* getItemAt(int index) {
			if (_jsonNode->type != Json_Array) {
				CCLOGERROR("Cannot call getItemAt on a node that is not an array");
				return nullptr;
			}
			Json* targetNode = Json_getItemAt(_jsonNode, index);
			JsonObject* result = JsonObject::create();
			result->setJsonNode(targetNode);
			return result;
		}

		int getInt() {
			return _jsonNode->valueint;
		}
		float getFloat() {
			return _jsonNode->valuefloat;
		}
		string getString() {
			return string(_jsonNode->valuestring);
		}

	};
}
#endif /* defined(__CodeBreaker__JsonObject__) */
