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

		// Single Touch Handlers
		virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
		virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
		virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
		virtual void ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent);

		CREATE_FUNC(GameplayLayer);
	};
}

#endif /* defined(__CodeBreaker__GameplayLayer__) */
