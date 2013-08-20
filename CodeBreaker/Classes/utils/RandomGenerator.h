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

namespace codebreaker {

	class RandomGenerator {

	private:
		std::default_random_engine* _generator;
		

	public:
		bool init();
		
		int getRandomInt(int min, int max);

	};
}

#endif
