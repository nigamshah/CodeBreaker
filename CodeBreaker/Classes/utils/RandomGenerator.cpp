//
//  RandomGenerator.cpp
//  CodeBreaker
//
//  Created by Nigam Shah on 8/20/13.
//
//

#include "RandomGenerator.h"
#include "ServiceLocator.h"
#include "Config.h"
#include "JsonObject.h"

using namespace codebreaker;
using namespace cocos2d;

default_random_engine* RandomGenerator::_generator;

void RandomGenerator::init() {
	_generator = new default_random_engine();

	time_t timer = time(nullptr);  /* get current time; same as: timer = time(NULL)  */
	std::string seedString = StringUtils::to_string(timer);
	CCLog("INTIIAL seedString = %s", seedString.c_str());

	JsonObject* settings = ServiceLocator::getConfig()->getJsonObject("main_seed");
	std::string userSeed = settings->getString();
	if (!userSeed.empty()) {
		CCLog("using User supplied seedString = %s", userSeed.c_str());
		seedString = userSeed;
	}
	_generator->seed(*seedString.c_str());


}

int RandomGenerator::getRandomInt(int min, int max) {
	std::uniform_int_distribution<int> distribution(min,max);
	int roll = distribution(*_generator);
	CCLog("dice roll int = %i", roll);
	return roll;
}
