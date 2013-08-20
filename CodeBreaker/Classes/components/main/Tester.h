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

		void init() {


			RandomGenerator::getRand(1, 10);


		}

	};
}
#endif /* defined(__CodeBreaker__Tester__) */
