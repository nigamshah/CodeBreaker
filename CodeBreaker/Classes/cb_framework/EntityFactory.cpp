//
//  EntityFactory.cpp
//  CodeBreaker
//
//  Created by Nigam Shah on 8/6/13.
//
//

#include "EntityFactory.h"
#include "MainController.h"
#include "SceneManager.h"
#include "GameModeMachine.h"

using namespace codebreaker;

EntityFactory::FactoryMap EntityFactory::s_factoryMap = {
	{ "Main", &EntityFactory::createMainEntity}
};

Entity* EntityFactory::createMainEntity(std::string eid) {
	Entity* ent = createBaseEntity(eid);

	ent->addComponentToEntity(MainController::create());
	ent->addComponentToEntity(SceneManager::create());
	ent->addComponentToEntity(GameModeMachine::create());
	
	return ent;
}

Entity* EntityFactory::createBoardEntity(std::string eid) {
	Entity* ent = createBaseEntity(eid);
	return ent;
}

Entity* EntityFactory::createBaseEntity(std::string eid) {
	Entity* ent = Entity::createWithEid(eid);
	return ent;
}

Entity* EntityFactory::createEntity(std::string templateId, std::string eid) {
	FactoryMethod method = s_factoryMap[templateId];
	if (!method) {
		method = &EntityFactory::createBaseEntity;
	}
	Entity* ent = method(eid);
	return ent;
}