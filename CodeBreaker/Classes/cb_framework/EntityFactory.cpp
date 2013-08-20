//
//  EntityFactory.cpp
//  CodeBreaker
//
//  Created by Nigam Shah on 8/6/13.
//
//

#include "EntityFactory.h"

// shared
#include "GameSpriteComponent.h"

// main
#include "MainController.h"
#include "SceneManager.h"
#include "GameModeMachine.h"
#include "GameplayInputMachine.h"

// board
#include "BoardView.h"
#include "BoardFactory.h"

using namespace codebreaker;

EntityFactory::FactoryMap EntityFactory::s_factoryMap = {
	{ "main", &EntityFactory::createMainEntity},
	{ "board", &EntityFactory::createBoardEntity},
	{ "cell", &EntityFactory::createCellEntity}
};

Entity* EntityFactory::createMainEntity(std::string eid) {
	Entity* ent = createBaseEntity(eid);

	ent->addComponentToEntity(SceneManager::create());
	ent->addComponentToEntity(GameModeMachine::create());
	ent->addComponentToEntity(GameplayInputMachine::create());
	
	return ent;
}

Entity* EntityFactory::createBoardEntity(std::string eid) {
	Entity* ent = createBaseEntity(eid);
	ent->addComponentToEntity(BoardView::create());
	ent->addComponentToEntity(BoardFactory::create());
	return ent;
}
Entity* EntityFactory::createCellEntity(std::string eid) {
	Entity* ent = createBaseEntity(eid);
	ent->addComponentToEntity(GameSpriteComponent::createWithSpriteFrameName("cell_bg.png"));
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
	ent->setTemplateId(templateId);
	return ent;
}