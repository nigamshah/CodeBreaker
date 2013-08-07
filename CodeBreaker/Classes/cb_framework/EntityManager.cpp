//
//  EntityManager.cpp
//  CodeBreaker
//
//  Created by Nigam Shah on 8/5/13.
//
//

#include "EntityManager.h"
#include "EntityFactory.h"

using namespace codebreaker;

EntityManager::EntityMap EntityManager::s_entitiesById = *(new EntityMap());

void EntityManager::deleteAllEntities() {
	for (auto& pr : s_entitiesById) {
		Entity* ent = pr.second;
		CC_SAFE_RELEASE(ent);
	}
	s_entitiesById.clear();
}


Entity* EntityManager::createEntity(std::string templateId, std::string eid) {
	Entity* ent = EntityFactory::createEntity(templateId, eid);
	ent->retain();
	s_entitiesById[eid] = ent;
	ent->start();
	return ent;
}

void EntityManager::deleteEntity(std::string eid) {
	Entity* ent = getEntity(eid);
	CC_SAFE_RELEASE(ent);
	s_entitiesById.erase(eid);
}

Entity* EntityManager::getEntity(std::string eid) {
	Entity* ent = s_entitiesById[eid];
	return ent;
}