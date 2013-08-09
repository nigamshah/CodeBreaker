//
//  GameSprite.h
//  CodeBreaker
//
//  Created by Nigam Shah on 8/9/13.
//
//

#ifndef __CodeBreaker__GameSprite__
#define __CodeBreaker__GameSprite__

#include "codebreaker.h"

namespace codebreaker {
	class GameSprite : public CCSprite {
	public:

		CC_SYNTHESIZE(Component*, _component, Component)

		static GameSprite* gameSpriteWithFile(const char * pszFileName);
		
	};
}

#endif /* defined(__CodeBreaker__GameSprite__) */
