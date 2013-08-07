//
//  MainGameLayer.h
//  CodeBreaker
//
//  Created by Nigam Shah on 8/7/13.
//
//

#ifndef __CodeBreaker__MainGameLayer__
#define __CodeBreaker__MainGameLayer__

#include "cocos2d.h"
using namespace cocos2d;

namespace codebreaker {
	class MainGameLayer : public CCLayer {

	public:
		//~MainGameLayer(void);
		virtual bool init();
		CREATE_FUNC(MainGameLayer);
	};
}

#endif /* defined(__CodeBreaker__MainGameLayer__) */
