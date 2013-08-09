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
	CC_SAFE_RELEASE(_gameplayScene);
	CC_SAFE_RELEASE(_gameOverScene);
	_currentScene = nullptr;
}

bool SceneManager::init() {
	if (!Component::init()) return false;

	_mainMenuScene = _createScene(MainMenuLayer::create());
	_mainMenuScene->retain();
	_gameplayScene = _createScene(MainGameLayer::create());
	_gameplayScene->retain();

	_currentScene = _mainMenuScene;
	CCDirector::sharedDirector()->runWithScene(_mainMenuScene);
	return true;
}

void SceneManager::awake() {
	_subscribe("switchScene", bind(&SceneManager::_switchSceneHandler, this, _1), "switchScene");
	_subscribe("addChildToScene", bind(&SceneManager::_addChildToSceneHandler, this, _1), "addChildToScene");
	_subscribe("removeChildFromScene", bind(&SceneManager::_removeChildFromSceneHandler, this, _1), "removeChildFromScene");
}

void SceneManager::start() {

}

void SceneManager::_switchSceneHandler(Message& msg) {

	string targetSceneName = *msg.getData<string*>();

	CCLog("targetSceneName = %s", targetSceneName.c_str());
	if (targetSceneName.compare("mainMenu") == 0) {
		_switchScene(_mainMenuScene);
	} else if (targetSceneName.compare("gameplay") == 0) {
		_switchScene(_gameplayScene);
	} else if (targetSceneName.compare("gameOver") == 0) {
		_switchScene(_gameOverScene);
	} else {
		CCLog("No Match for targetSceneName = %s", targetSceneName.c_str());
	}
}

void SceneManager::_switchScene(CCScene* pScene) {
	CCDirector::sharedDirector()->replaceScene(pScene);
	_currentScene = pScene;
}


CCScene* SceneManager::_createScene(CCLayer* pLayer) {
	// 'scene' is an autorelease object
	CCScene *pScene = CCScene::create();

	// add layer as a child to scene
	pScene->addChild(pLayer);

    // return the scene
	return pScene;
}

void SceneManager::_addChildToSceneHandler(Message& msg) {
	// unpack msg
	CCNode* node = msg.getData<CCNode*>();
	_addChildToScene(node);
}
void SceneManager::_addChildToScene(CCNode* node) {
	_currentScene->addChild(node);
}
void SceneManager::_removeChildFromSceneHandler(Message& msg) {
	// unpack msg
	CCNode* node = msg.getData<CCNode*>();
	_removeChildFromScene(node);
}
void SceneManager::_removeChildFromScene(CCNode* node) {
	_currentScene->removeChild(node);
}

