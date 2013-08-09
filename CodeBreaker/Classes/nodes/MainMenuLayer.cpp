//
//  MainMenuLayer.cpp
//  CodeBreaker
//
//  Created by Nigam Shah on 8/5/13.
//
//

#include "MainMenuLayer.h"
#include "EntityManager.h"

using namespace codebreaker;

MainMenuLayer::~MainMenuLayer() {

}

// on "init" you need to initialize your instance
bool MainMenuLayer::init()
{
	//////////////////////////////
	// 1. super init first
	if (!CCLayer::init()) {
		return false;
	}

	/////////////////////////////
	// 2. add a menu item with "X" image, which is clicked to quit the program
	//    you may modify it.

	// add a "start" icon to start the game. it's an autorelease object
	CCMenuItemImage *pStartItem = CCMenuItemImage::create(
														  "CloseNormal.png",
														  "CloseSelected.png",
														  this,
														  menu_selector(MainMenuLayer::startGameCallback) );

	pStartItem->setPosition( ccp(CCDirector::sharedDirector()->getWinSize().width - 20, 100) );


	// add a "close" icon to exit the progress. it's an autorelease object
	CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
														  "CloseNormal.png",
														  "CloseSelected.png",
														  this,
														  menu_selector(MainMenuLayer::menuCloseCallback) );

	pCloseItem->setPosition( ccp(CCDirector::sharedDirector()->getWinSize().width - 20, 20) );

	// create menu, it's an autorelease object
	CCMenu* pMenu = CCMenu::create(pStartItem, pCloseItem, NULL);

	pMenu->setPosition( CCPointZero );
	this->addChild(pMenu, 1);

	/////////////////////////////
	// 3. add your codes below...

	// add a label shows "Hello World"
	// create and initialize a label
	CCLabelTTF* pLabel = CCLabelTTF::create("Main Menu: top button to start, bottom button to quit", "Thonburi", 34);

	// ask director the window size
	CCSize size = CCDirector::sharedDirector()->getWinSize();

	// position the label on the center of the screen
	pLabel->setPosition( ccp(size.width / 2, size.height - 20) );

	// add the label as a child to this layer
	this->addChild(pLabel, 1);

	// add "MainMenu" splash screen"
	CCSprite* pSprite = CCSprite::create("HelloWorld.png");

	// position the sprite on the center of the screen
	pSprite->setPosition( ccp(size.width/2, size.height/2) );

	// add the sprite as a child to this layer
	this->addChild(pSprite, 0);

	return true;
}

void MainMenuLayer::startGameCallback(CCObject* pSender) {
	CCLog("Start Game Event HERE !!!!");
	EntityManager::sendMessageToEntity("main", "startGame", this, nullptr);
}

void MainMenuLayer::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}