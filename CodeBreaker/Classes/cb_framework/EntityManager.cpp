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


void EntityManager::sendMessageToEntity(std::string eid, std::string message, cocos2d::CCObject* sender, void* data) {
	Message* msgObj = new Message(message, sender, data);
	Entity* ent = getEntity(eid);
	if (ent) {
		ent->sendLocalMessage(message, msgObj);
	} else {
		cocos2d::CCLog("No Entity with eid = %s", eid.c_str());
	}
}
void EntityManager::sendMessageToAllEntities(std::string message, cocos2d::CCObject* sender, void* data) {
	Message* msgObj = new Message(message, sender, data);
	for (auto& pr : s_entitiesById) {
		Entity* ent = pr.second;
		ent->sendLocalMessage(message, msgObj);
	}
}