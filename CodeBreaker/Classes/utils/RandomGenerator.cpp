//
//  RandomGenerator.cpp
//  CodeBreaker
//
//  Created by Nigam Shah on 8/20/13.
//
//


#include "RandomGenerator.h"
#include "cocos2d.h"

#include "ServiceLocator.h"
#include "Config.h"
#include "JsonObject.h"
#include "StringUtils.h"

using namespace codebreaker;
using namespace cocos2d;

bool RandomGenerator::init() {

	time_t timer = time(nullptr);  /* get current time; same as: timer = time(NULL)  */
	std::string seedString = StringUtils::to_string(timer);
	CCLog("INTIIAL seedString = %s", seedString.c_str());

	JsonObject* settings = ServiceLocator::getConfig().getJsonObject("main_seed");
	std::string userSeed = settings->getString();
	if (!userSeed.empty()) {
		CCLog("using User supplied seedString = %s", userSeed.c_str());
		seedString = userSeed;
	}
	_generator.seed(*seedString.c_str());

	return true;
}

int RandomGenerator::getRandomInt(int min, int max) {
	std::uniform_int_distribution<int> distribution(min,max);
	int roll = distribution(_generator);
	CCLog("dice roll int = %i", roll);
	return roll;
}
