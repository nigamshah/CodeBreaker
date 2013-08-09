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
		friend class EntityManager;
//	private:
		typedef std::function<Entity* (std::string)> FactoryMethod;
		typedef std::map<std::string, FactoryMethod> FactoryMap;

		static FactoryMap s_factoryMap;

		static Entity* createBaseEntity(std::string eid);
		static Entity* createMainEntity(std::string eid);
		static Entity* createBoardEntity(std::string eid);
		static Entity* createCellEntity(std::string eid);
		static Entity* createEntity(std::string templateId, std::string eid);


	};
}


#endif /* defined(__CodeBreaker__EntityFactory__) */
