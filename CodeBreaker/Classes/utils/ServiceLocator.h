//
//  ServiceLocator.h
//  CodeBreaker
//
//  Created by Nigam Shah on 8/14/13.
//
//

#ifndef __CodeBreaker__ServiceLocator__
#define __CodeBreaker__ServiceLocator__

#include "codebreaker.h"
#include "Config.h"

namespace codebreaker {

	class ServiceLocator {
	private:
		static Config* s_config;

	public:

		static void init();

		static Config* getConfig() {
			return s_config;
		};
		static CCDirector* getDirector() {
			return CCDirector::sharedDirector();
		}


	};
}


#endif /* defined(__CodeBreaker__ServiceLocator__) */