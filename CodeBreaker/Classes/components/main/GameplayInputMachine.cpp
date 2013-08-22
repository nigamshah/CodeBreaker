//
//  GameplayInputMachine.cpp
//  CodeBreaker
//
//  Created by Nigam Shah on 8/15/13.
//
//

#include "GameplayInputMachine.h"
#include "BoardView.h"
#include "GameSpriteComponent.h"

////////////////////////////////////////
//	InputStateReady
////////////////////////////////////////
void InputStateReady::onEnter(Message& message) {
	CCLog("InputStateReady.onEnter %s", message.getName().c_str());

	_messenger.subscribe("touchBegan", std::bind(&InputStateReady::_onTouchBegan, this, std::placeholders::_1), "touchBegan");

	GameplayLayer* layer = static_cast<GameplayInputMachine*>(_machine)->getGameplayLayer();
	layer->setTouchEnabled(true);
}

void InputStateReady::_onTouchBegan(Message& message) {
	CCTouch* pTouch = static_cast<CCTouch*>(message.getData());
	CCPoint touchLocation = pTouch->getLocation();
	CCLog("----- touched at: x = %f / y = %f", touchLocation.x, touchLocation.y);

	Entity* pBoardEnt = EntityManager::getEntity("board");
	BoardView* boardView = pBoardEnt->getComponentByType<BoardView>();

	bool isOnBoard = boardView->containsPoint(touchLocation);
	CCLog("isOnBoard = %i", isOnBoard);

	if (isOnBoard) {
		// check the cells
		// get all the cells
		EntityList* pCellList = EntityManager::getEntitiesByTemplateId("cell");
		string cellId = "";
		for (Entity* pCell : *pCellList) {
			GameSpriteComponent* spriteComp = pCell->getComponentByType<GameSpriteComponent>();

			bool isOnCell = spriteComp->containsWorldPoint(touchLocation);
			if (isOnCell) {
				cellId = pCell->getEid();
				break;
			}
		}
		if (!cellId.empty()) {
			CCLog("found Cell! entity id = %s", cellId.c_str());
		} else {
			CCLog("no cell found");
		}

	}
	
}


//		// get location of touch as a CCPoint
//		touchLocation = pTouch->getLocation();

// iterate through the cells and determine which, if any cell was touched

//		for (int p = 0; p < 2; p++) {
//			player = (GameSprite *) _players->objectAtIndex(p);
//			if (player->boundingBox().containsPoint(tap)) {
//				player->setTouch(touch);
//			}
//		}


void InputStateReady::onExit(Message& message) {
	CCLog("InputStateReady.onExit %s", message.getName().c_str());
	GameplayLayer* layer = static_cast<GameplayInputMachine*>(_machine)->getGameplayLayer();
	layer->setTouchEnabled(false);
}


////////////////////////////////////////
//	InputStateDisabled
////////////////////////////////////////
void InputStateDisabled::onEnter(Message& message) {
	CCLog("InputStateDisabled.onEnter %s", message.getName().c_str());
	GameplayLayer* layer = static_cast<GameplayInputMachine*>(_machine)->getGameplayLayer();
	layer->setTouchEnabled(false);
}

void InputStateDisabled::onExit(Message& message) {
	CCLog("InputStateDisabled.onExit %s", message.getName().c_str());
	GameplayLayer* layer = static_cast<GameplayInputMachine*>(_machine)->getGameplayLayer();
	layer->setTouchEnabled(false);
}

////////////////////////////////////////
//	InputStateDragging
////////////////////////////////////////
void InputStateDragging::onEnter(Message& message) {
	CCLog("InputStateDragging.onEnter %s", message.getName().c_str());
	GameplayLayer* layer = static_cast<GameplayInputMachine*>(_machine)->getGameplayLayer();
	layer->setTouchEnabled(true);
}
void InputStateDragging::onExit(Message& message) {
	CCLog("InputStateDragging.onExit %s", message.getName().c_str());
	GameplayLayer* layer = static_cast<GameplayInputMachine*>(_machine)->getGameplayLayer();
	layer->setTouchEnabled(false);
}