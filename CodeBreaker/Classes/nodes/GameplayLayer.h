//
//  MainGameLayer.h
//  CodeBreaker
//
//  Created by Nigam Shah on 8/7/13.
//
//

#ifndef __CodeBreaker__GameplayLayer__
#define __CodeBreaker__GameplayLayer__

#include "cocos2d.h"
using namespace cocos2d;

namespace codebreaker {
	class GameplayLayer : public CCLayer {

	public:
		//~GameplayLayer(void);
		virtual bool init();
		virtual void ccTouchesBegan(CCSet* pTouches, CCEvent* event);
		virtual void ccTouchesMoved(CCSet* pTouches, CCEvent* event);
		virtual void ccTouchesEnded(CCSet* pTouches, CCEvent* event);

		CREATE_FUNC(GameplayLayer);
	};
}

#endif /* defined(__CodeBreaker__GameplayLayer__) */
