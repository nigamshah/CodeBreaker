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

	this->setTouchMode(ccTouchesMode::kCCTouchesOneByOne);
	this->setTouchEnabled(true);

	return true;
}


/////////////////////////////////////////////
//	Touch Handlers
/////////////////////////////////////////////

bool GameplayLayer::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent) {
	CCLog("TouchBegan");

	// this is the boilerplate collision detection code from "Air Hockey"
	


	return true;
}
void GameplayLayer::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent) {
	CCLog("TouchMoved");
}
void GameplayLayer::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent) {
	CCLog("TouchEnded");
}
void GameplayLayer::ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent) {
	CCLog("TouchCancelled");
}