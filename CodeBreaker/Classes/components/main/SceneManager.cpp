//
//  SceneManager.cpp
//  CodeBreaker
//
//  Created by Nigam Shah on 8/7/13.
//
//

#include "SceneManager.h"
#include "MainMenuLayer.h"
#include "MainGameLayer.h"

SceneManager::~SceneManager() {
	CC_SAFE_RELEASE(_mainMenuScene);
	CC_SAFE_RELEASE(_gameScene);
	CC_SAFE_RELEASE(_gameOverScene);
}

bool SceneManager::init() {
	if (!Component::init()) return false;

	_mainMenuScene = _createScene(MainMenuLayer::create());
	_mainMenuScene->retain();
	_gameScene = _createScene(MainGameLayer::create());
	_gameScene->retain();

	CCDirector::sharedDirector()->runWithScene(_mainMenuScene);
	return true;
}

void SceneManager::awake() {
	_subscribe("switchScene", bind(&SceneManager::switchScene, this, _1), "switchScene");
}

void SceneManager::start() {

}

void SceneManager::switchScene(Message& msg) {

	string targetSceneName = *msg.getData<string*>();

	CCLog("targetSceneName = %s", targetSceneName.c_str());
	if (targetSceneName.compare("MainMenu") == 0) {
		_switchScene(_mainMenuScene);
	} else if (targetSceneName.compare("Game") == 0) {
		_switchScene(_gameScene);
	} else if (targetSceneName.compare("GameOver") == 0) {
		_switchScene(_gameOverScene);
	} else {
		CCLog("No Match for targetSceneName = %s", targetSceneName.c_str());
	}
}

void SceneManager::_switchScene(CCScene* pScene) {
	CCDirector::sharedDirector()->replaceScene(pScene);
}


CCScene* SceneManager::_createScene(CCLayer* pLayer) {
	// 'scene' is an autorelease object
	CCScene *pScene = CCScene::create();

	// add layer as a child to scene
	pScene->addChild(pLayer);

    // return the scene
	return pScene;
}