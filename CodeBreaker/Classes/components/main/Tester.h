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

			for (int i = 0; i < 5; i++) {
				int n = ServiceLocator::getRandomGenerator().getRandomInt(0, 9);
			}
			return true;
			
		}

	};
}
#endif /* defined(__CodeBreaker__Tester__) */
