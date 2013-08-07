//
//  MainMenuLayer.h
//  CodeBreaker
//
//  Created by Nigam Shah on 8/5/13.
//
//

#ifndef __CodeBreaker__MainMenuLayer__
#define __CodeBreaker__MainMenuLayer__

#include "cocos2d.h"

using namespace cocos2d;

namespace codebreaker {
	class MainMenuLayer : public CCLayer
	{

	public:
		~MainMenuLayer(void);

		// Method 'init' in cocos2d-x returns bool, instead of 'id' in cocos2d-iphone (an object pointer)
		virtual bool init();


		// selector callbacks
		void startGameCallback(CCObject* pSender);
		void menuCloseCallback(CCObject* pSender);

		// preprocessor macro for "static create()" constructor ( node() deprecated )
		CREATE_FUNC(MainMenuLayer);

	};
}

#endif /* defined(__CodeBreaker__MainMenuLayer__) */
