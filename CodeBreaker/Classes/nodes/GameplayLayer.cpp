//
//  MainGameLayer.cpp
//  CodeBreaker
//
//  Created by Nigam Shah on 8/7/13.
//
//

#include "GameplayLayer.h"

using namespace codebreaker;

// on "init" you need to initialize your instance
bool GameplayLayer::init()
{
	//////////////////////////////
	// 1. super init first
	if (!CCLayer::init()) {
		return false;
	}

	// ask director the window size
	CCSize size = CCDirector::sharedDirector()->getWinSize();

	// add "MainLayer" bg sprite
	CCSprite* pSprite = CCSprite::create("game_bg_level1.jpg");

	// position the sprite on the center of the screen
	pSprite->setPosition( ccp(size.width/2, size.height/2) );

	// add the sprite as a child to this layer
	this->addChild(pSprite, 0);

	this->setTouchEnabled(true);

	return true;
}
void GameplayLayer::ccTouchesBegan(CCSet* pTouches, CCEvent* event) {
	CCLog("Touches Began");

}
void GameplayLayer::ccTouchesMoved(CCSet* pTouches, CCEvent* event) {
	CCLog("Touches Moved");
}
void GameplayLayer::ccTouchesEnded(CCSet* pTouches, CCEvent* event) {
	CCLog("Touches Ended");
}
