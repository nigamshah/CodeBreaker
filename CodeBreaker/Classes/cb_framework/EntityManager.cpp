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

std::map<std::string, codebreaker::Entity*> EntityManager::s_entitiesById = *(new std::map<std::string, Entity*>());
std::map<std::string, codebreaker::EntityList*> EntityManager::s_entitiesByTemplateId = *(new std::map<std::string, EntityList*>());

void EntityManager::deleteAllEntities() {
	for (auto& pr : s_entitiesById) {
		Entity* ent = pr.second;
		CC_SAFE_RELEASE(ent);
	}
	s_entitiesById.clear();

	for (auto& pr : s_entitiesByTemplateId) {
		EntityList* entList = pr.second;
		entList->clear();
	}
	s_entitiesByTemplateId.clear();
}


Entity* EntityManager::createEntity(std::string templateId, std::string eid) {
	Entity* ent = EntityFactory::createEntity(templateId, eid);
	ent->retain();

	EntityList* pEntList = getEntitiesByTemplateId(templateId);
	if (!pEntList) {
		pEntList = new EntityList();
		s_entitiesByTemplateId[templateId] = pEntList;
	}
	pEntList->push_back(ent);
	s_entitiesById[eid] = ent;
	ent->start();
	return ent;
}

void EntityManager::deleteEntity(std::string eid) {
	Entity* ent = getEntity(eid);
	std::string templateId = ent->getTemplateId();
	EntityList* entList = getEntitiesByTemplateId(templateId);
	entList->remove(ent);
	s_entitiesById.erase(eid);
	CC_SAFE_RELEASE(ent);
}

Entity* EntityManager::getEntity(std::string eid) {
	Entity* ent = s_entitiesById[eid];
	return ent;
}
EntityList* EntityManager::getEntitiesByTemplateId(std::string templateId) {
	EntityList* result = s_entitiesByTemplateId[templateId];
	return result;
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