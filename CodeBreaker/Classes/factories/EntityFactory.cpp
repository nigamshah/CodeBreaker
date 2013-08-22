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
#include "SceneManager.h"
#include "GameModeMachine.h"
#include "GameplayInputMachine.h"

// board
#include "BoardView.h"
#include "BoardFactory.h"

// tile
#include "TileMaterial.h"

using namespace codebreaker;

Entity* EntityFactory::createBaseEntity(std::string eid) {
	Entity* ent = Entity::createWithEid(eid);
	return ent;
}

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

Entity* EntityFactory::createTileEntity(std::string eid) {
	Entity* ent = createBaseEntity(eid);
	ent->addComponentToEntity(TileMaterial::create());
	return ent;
}








