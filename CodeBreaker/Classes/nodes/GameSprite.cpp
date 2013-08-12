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
	return nullptr;
}

GameSprite* GameSprite::gameSpriteWithSpriteFrame(CCSpriteFrame* pSpriteFrame) {
	GameSprite* sprite = new GameSprite();
	if (sprite && sprite->initWithSpriteFrame(pSpriteFrame)) {
		sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}
GameSprite* GameSprite::gameSpriteWithSpriteFrameName(const char * pszSpriteFrameName) {
	GameSprite* sprite = new GameSprite();
	if (sprite && sprite->initWithSpriteFrameName(pszSpriteFrameName)) {
		sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}
