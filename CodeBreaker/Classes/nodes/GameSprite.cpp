//
//  GameSprite.cpp
//  CodeBreaker
//
//  Created by Nigam Shah on 8/9/13.
//
//

#include "GameSprite.h"

GameSprite* GameSprite::gameSpriteWithFile(const char * pszFileName) {
	GameSprite* sprite = new GameSprite();
	if (sprite && sprite->initWithFile(pszFileName)) {
		sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return NULL;
}