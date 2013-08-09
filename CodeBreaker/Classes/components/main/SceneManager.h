//
//  SceneManager.h
//  CodeBreaker
//
//  Created by Nigam Shah on 8/7/13.
//
//

#ifndef __CodeBreaker__SceneManager__
#define __CodeBreaker__SceneManager__

#include "codebreaker.h"

namespace codebreaker {
	class SceneManager : public Component {
	private:

		CCScene* _mainMenuScene;
		CCScene* _gameplayScene;
		CCScene* _gameOverScene;
		CCScene* _currentScene;

		CCScene* _createScene(CCLayer* pLayer);

		void _switchSceneHandler(Message& msg);
		void _switchScene(CCScene* pScene);

		void _addChildToSceneHandler(Message& msg);
		void _addChildToScene(CCNode* node);

		void _removeChildFromSceneHandler(Message& msg);
		void _removeChildFromScene(CCNode* node);

	public:

		~SceneManager();

		virtual bool init();
		virtual void awake();
		virtual void start();

		CREATE_FUNC(SceneManager);
	};
}

#endif /* defined(__CodeBreaker__SceneManager__) */