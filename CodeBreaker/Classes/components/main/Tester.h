//
//  Tester.h
//  CodeBreaker
//
//  Created by Nigam Shah on 8/13/13.
//
//

#ifndef __CodeBreaker__Tester__
#define __CodeBreaker__Tester__

#include "codebreaker.h"
#include "RandomGenerator.h"

namespace codebreaker {
	using namespace cocos2d::extension;

	class Tester {

	public:

		bool init() {

			EntityManager::createEntity("tile", "testTile");

			return true;
		}

		void onSwitchScene(Message& msg) {
			std::string sceneId = *(msg.getData<std::string*>());

			if (sceneId.compare("gameplay") == 0) {
				CCLog("gameplay!");

			} else {
				//
				CCLog("sceneId = %s", sceneId.c_str());
			}

		}

	};
}
#endif /* defined(__CodeBreaker__Tester__) */
