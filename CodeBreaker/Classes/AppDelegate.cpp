//
//  CodeBreakerAppDelegate.cpp
//  CodeBreaker
//
//  Created by Nigam Shah on 8/5/13.
//  Copyright __MyCompanyName__ 2013. All rights reserved.
//

#include "AppDelegate.h"

#include "cocos2d.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;
using namespace CocosDenshion;

AppDelegate::AppDelegate()
{

}

AppDelegate::~AppDelegate()
{
}

bool AppDelegate::applicationDidFinishLaunching()
{
    // initialize director
    CCDirector *pDirector = CCDirector::sharedDirector();
    pDirector->setOpenGLView(CCEGLView::sharedOpenGLView());

    // turn on display FPS
    pDirector->setDisplayStats(false);

    // set FPS. the default value is 1.0/60 if you don't call this
    pDirector->setAnimationInterval(1.0 / 60);


	// set search paths
	std::vector<std::string> searchPaths;

		//	Not using this now, but it is a good thing to remember....
		//	- Nigam

		//	if (screenSize.width > 768) {
		//		searchPaths.push_back("hd");
		//		pDirector->setContentScaleFactor(2);
		//	} else {
		//		searchPaths.push_back("sd");
		//		pDirector->setContentScaleFactor(1);
		//	}

	searchPaths.push_back("game_data");
	searchPaths.push_back("game_images");
	searchPaths.push_back("game_images/tile_sprites");

	CCFileUtils::sharedFileUtils()->setSearchPaths(searchPaths);

	// Main - the actual game init stuff starts here
	codebreaker::EntityManager::createEntity("Main", "main");

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground()
{
    CCDirector::sharedDirector()->stopAnimation();
    SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
    SimpleAudioEngine::sharedEngine()->pauseAllEffects();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground()
{
    CCDirector::sharedDirector()->startAnimation();
    SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
    SimpleAudioEngine::sharedEngine()->resumeAllEffects();
}
