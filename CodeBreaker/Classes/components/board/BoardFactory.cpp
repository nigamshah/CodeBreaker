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
#include "BoardView.h"

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
	CCSpriteBatchNode* cells = CCSpriteBatchNode::create("tile_spritesheet.png");

	CCSize screenSize = ServiceLocator::getDirector()->getWinSize();

	JsonObject* settings = ServiceLocator::getConfig()->getComponentSettings("board", "board_factory");

	JsonObject* gridSizeSettings = settings->getChild("grid_size");
	const float cellSize = gridSizeSettings->getChild("cell_size")->getFloat();
	const float cellPadding = gridSizeSettings->getChild("cell_padding")->getFloat();
	const int numColumns = gridSizeSettings->getChild("num_columns")->getInt();
	const int numRows = gridSizeSettings->getChild("num_rows")->getInt();
	const float offset = (cellSize + cellPadding) / 2;

	for (int column = 0; column < numColumns; column++) {
		for (int row = 0; row < numRows; row++) {
			string cellId = "cell_" + to_string(column) + "." + to_string(row);
			Entity* ent = EntityManager::createEntity("cell", cellId);
			GameSpriteComponent* comp = ent->getComponentByType<GameSpriteComponent>();
			GameSprite* sprite = comp->getGameSprite();
			sprite->setPosition(ccp(column * (cellSize + cellPadding) + offset, row * (cellSize + cellPadding) + offset));
			cells->addChild(sprite);
		}
	}

	float boardWidth = numColumns * (cellSize + cellPadding);
	float boardHeight = numRows * (cellSize + cellPadding);
	CCSize boardSize = CCSize(boardWidth, boardHeight);

	float boardX = (screenSize.width - boardWidth) / 2;
	float boardY = boardX;

	cells->setContentSize(boardSize);
	cells->setPosition(ccp(boardX, boardY));

	BoardView* pBoardView = _entity->getComponentByType<BoardView>();
	pBoardView->addCells(cells);
	CCNode* boardNode = pBoardView->getNode();

	sendMessageToEntity("main", "addChildToScene", boardNode);
}