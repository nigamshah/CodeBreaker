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
	class RandomGenerator {

	private:

	public:
		static int getRand(int min, int max) {
			std::default_random_engine generator;
			std::default_random_engine generator1;
			std::uniform_int_distribution<int> distribution(min,max);

//			int time = getCurrentTime();
			int time = 2000;
			generator.seed(time);

			std::string s = "Badaboom";
			generator1.seed(*s.c_str());

			int roll = 0;

			for (int i = 0; i < 5; i++) {
				roll = distribution(generator);
				CCLog("dice roll int = %i", roll);

				roll = distribution(generator1);
				CCLog("dice roll String = %i", roll);
			}

			return roll;

		}


		static int getCurrentTime ()
		{
			time_t timer;
//			struct tm y2k;
//			double seconds;
//
//			y2k.tm_hour = 0;   y2k.tm_min = 0; y2k.tm_sec = 0;
//			y2k.tm_year = 100; y2k.tm_mon = 0; y2k.tm_mday = 1;

			timer = time(nullptr);  /* get current time; same as: timer = time(NULL)  */
			std::string str = StringUtils::to_string(timer);

			CCLog("str = %li", timer);
			CCLog("str = %s", str.c_str());


//			seconds = difftime(timer,mktime(&y2k));


			return 0;
		}



	};
}

#endif
