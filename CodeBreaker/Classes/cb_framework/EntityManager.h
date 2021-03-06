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

	typedef std::list<codebreaker::Entity*> EntityList;
	typedef std::function<Entity* (std::string)> FactoryMethod;
	typedef std::map<std::string, FactoryMethod> FactoryMap;

	class EntityManager {

	public:
		static void registerFactoryMethod(std::string templateId, FactoryMethod method);

		static Entity* createEntity(std::string templateId, std::string eid);

		static void deleteEntity(std::string eid);

		static Entity* getEntity(std::string eid);
		static EntityList* getEntitiesByTemplateId(std::string templateId);
		static void deleteAllEntities();

		static void sendMessageToEntity(std::string eid, std::string message, cocos2d::CCObject* sender, void* data);

		static void sendMessageToAllEntities(std::string message, cocos2d::CCObject* sender, void* data);

	private:
		static FactoryMap s_factoryMap;

		static Entity* addEntity(std::string eid, Entity* ent);

		static std::map<std::string, Entity*> s_entitiesById;
		static std::map<std::string, EntityList*> s_entitiesByTemplateId;
		static Entity* createBaseEntity(std::string eid);
	};
}

#endif /* defined(__CodeBreaker__EntityManager__) */
