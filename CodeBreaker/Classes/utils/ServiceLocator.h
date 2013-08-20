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
#include "RandomGenerator.h"
#include "EntityFactory.h"
namespace codebreaker {

	class ServiceLocator {
	private:
		static Config s_config;
		static RandomGenerator s_randomGenerator;
		static EntityFactory s_entityFactory;


	public:

		static Config& getConfig() {
			return s_config;
		};

		static RandomGenerator& getRandomGenerator() {
			return s_randomGenerator;
		}

		static EntityFactory& getEntityFactory() {
			return s_entityFactory;
		};

		static CCDirector* getDirector() {
			return CCDirector::sharedDirector();
		}


	};
}


#endif /* defined(__CodeBreaker__ServiceLocator__) */