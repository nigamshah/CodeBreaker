//
//  EntityManager.h
//  CodeBreaker
//
//  Created by Nigam Shah on 8/5/13.
//
//

#ifndef __CodeBreaker__EntityManager__
#define __CodeBreaker__EntityManager__

#include "cocos2d.h"
#include "Entity.h"



namespace codebreaker {

	class EntityManager {

	public:
		static Entity* createEntity(std::string templateId, std::string eid);

		static void deleteEntity(std::string eid);

		static Entity* getEntity(std::string eid);

		static void deleteAllEntities();

	private:
		static Entity* addEntity(std::string eid, Entity* ent);
		typedef std::map<std::string, codebreaker::Entity*> EntityMap;
		static EntityMap s_entitiesById;
		
	};
}

#endif /* defined(__CodeBreaker__EntityManager__) */
