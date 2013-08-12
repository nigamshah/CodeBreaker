//
//  BoardFactory.cpp
//  CodeBreaker
//
//  Created by Nigam Shah on 8/9/13.
//
//

#include "BoardFactory.h"
#include "GameSprite.h"
#include "GameSpriteComponent.h"

using namespace codebreaker;

void BoardFactory::start() {

	///////////////////////////////////////
	//	init tile spritesheet
	///////////////////////////////////////
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("tile_spritesheet.plist");

	///////////////////////////////////////


	_createCells();
}

void BoardFactory::_createCells() {
	CCSpriteBatchNode* board = CCSpriteBatchNode::create("tile_spritesheet.png");

	CCSize screenSize = CCDirector::sharedDirector()->getWinSize();

	const float cellSize = 96.0;
	const float cellPadding = 0;
	const int numColumns = 5;
	const int numRows = 5;

	for (int column = 0; column < numColumns; column++) {
		for (int row = 0; row < numRows; row++) {
			string cellId = "cell_" + to_string(column) + "." + to_string(row);
			Entity* ent = EntityManager::createEntity("Cell", cellId);
			ComponentList* gameSpriteComponents = ent->getComponentsByType<GameSpriteComponent>();
			GameSpriteComponent* comp = static_cast<GameSpriteComponent*>(gameSpriteComponents->front());
			GameSprite* sprite = comp->getGameSprite();
			sprite->setPosition(ccp(column * (cellSize + cellPadding), row * (cellSize + cellPadding)));
			board->addChild(sprite);
		}
	}

	float boardX = ((cellSize + cellPadding) / 2) + (screenSize.width - (numColumns * (cellSize + cellPadding))) / 2;
	float boardY = boardX;

	board->setPosition(ccp(boardX, boardY));

	sendMessageToEntity("main", "addChildToScene", board);
}