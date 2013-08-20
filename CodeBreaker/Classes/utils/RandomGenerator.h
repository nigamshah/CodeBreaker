//
//  RandomGenerator.h
//  CodeBreaker
//
//  Created by Nigam Shah on 8/19/13.
//
//

#ifndef CodeBreaker_RandomGenerator_h
#define CodeBreaker_RandomGenerator_h

#include "random"
#include "cocos2d.h"
#include "StringUtils.h"

namespace codebreaker {
	using namespace std;
	using namespace cocos2d;

	class RandomGenerator {

	private:
		static default_random_engine* _generator;
		

	public:
		static void init();
		
		static int getRandomInt(int min, int max);

	};
}

#endif
