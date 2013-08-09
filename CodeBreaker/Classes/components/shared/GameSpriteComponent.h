//
//  GameSpriteComponent.h
//  CodeBreaker
//
//  Created by Nigam Shah on 8/9/13.
//
//

#ifndef __CodeBreaker__GameSpriteComponent__
#define __CodeBreaker__GameSpriteComponent__

#include "codebreaker.h"
#include "GameSprite.h"

namespace codebreaker {
	class GameSpriteComponent : public Component {

	public:

		CC_SYNTHESIZE_RETAIN(GameSprite*, _gameSprite, GameSprite);

		~GameSpriteComponent() {
			CC_SAFE_RELEASE(_gameSprite);
		}

		static GameSpriteComponent* createWithFileName(const char * fileName) {
			GameSprite* sprite = GameSprite::gameSpriteWithFile(fileName);
			if (!sprite) return nullptr;

			GameSpriteComponent* comp = GameSpriteComponent::create();
			comp->setGameSprite(sprite);
			sprite->setComponent(comp);
			return comp;
		}

		CREATE_FUNC(GameSpriteComponent);

	};
}

#endif /* defined(__CodeBreaker__GameSpriteComponent__) */