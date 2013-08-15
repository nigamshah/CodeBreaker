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
	//		this should go in a sprite factory
	//		of some sort (later)
	///////////////////////////////////////
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("tile_spritesheet.plist");

	///////////////////////////////////////


	_createCells();
}

void BoardFactory::_createCells() {
	CCSpriteBatchNode* board = CCSpriteBatchNode::create("tile_spritesheet.png");

	CCSize screenSize = ServiceLocator::getDirector()->getWinSize();

	JsonObject* settings = ServiceLocator::getConfig()->getComponentSettings("board", "board_factory");

	JsonObject* gridSizeSettings = settings->getChild("grid_size");
	const float cellSize = gridSizeSettings->getChild("cell_size")->getFloat();
	const float cellPadding = gridSizeSettings->getChild("cell_padding")->getFloat();
	const int numColumns = gridSizeSettings->getChild("num_columns")->getInt();
	const int numRows = gridSizeSettings->getChild("num_rows")->getInt();

	for (int column = 0; column < numColumns; column++) {
		for (int row = 0; row < numRows; row++) {
			string cellId = "cell_" + to_string(column) + "." + to_string(row);
			Entity* ent = EntityManager::createEntity("cell", cellId);
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