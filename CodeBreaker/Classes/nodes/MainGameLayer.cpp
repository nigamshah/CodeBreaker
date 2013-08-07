//
//  MainGameLayer.cpp
//  CodeBreaker
//
//  Created by Nigam Shah on 8/7/13.
//
//

#include "MainGameLayer.h"

using namespace codebreaker;

// on "init" you need to initialize your instance
bool MainGameLayer::init()
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

	return true;
}