//
//  EntityFactory.h
//  CodeBreaker
//
//  Created by Nigam Shah on 8/6/13.
//
//

#ifndef __CodeBreaker__EntityFactory__
#define __CodeBreaker__EntityFactory__

#include "cocos2d.h"
#include "EntityManager.h"
#include "Entity.h"

namespace codebreaker {


	class EntityFactory {

	private:
		static Entity* createBaseEntity(std::string eid);
		static Entity* createMainEntity(std::string eid);
		static Entity* createBoardEntity(std::string eid);
		static Entity* createCellEntity(std::string eid);

	public:

		bool init() {
			EntityManager::registerFactoryMethod("base", &EntityFactory::createBaseEntity);
			EntityManager::registerFactoryMethod("main", &EntityFactory::createMainEntity);
			EntityManager::registerFactoryMethod("board", &EntityFactory::createBoardEntity);
			EntityManager::registerFactoryMethod("cell", &EntityFactory::createCellEntity);
			return true;
		}

	};
}


#endif /* defined(__CodeBreaker__EntityFactory__) */
