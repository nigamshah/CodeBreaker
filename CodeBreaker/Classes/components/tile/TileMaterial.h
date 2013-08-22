//
//  TileMaterial.h
//  CodeBreaker
//
//  Created by Nigam Shah on 8/22/13.
//
//

#ifndef __CodeBreaker__TileMaterial__
#define __CodeBreaker__TileMaterial__

#include "codebreaker.h"
#include "GameSpriteComponent.h"

namespace codebreaker {

	enum class TileMaterialType {
		None,
		Wood,
		Bronze,
		Silver,
		Gold
	};

	class TileMaterial : public GameSpriteComponent {
		CC_SYNTHESIZE(TileMaterialType, _type, Type);

	public:
		virtual bool init() {
			_type = TileMaterialType::Bronze;
			return true;
		}

		virtual void start() {
		}

	};
}

#endif /* defined(__CodeBreaker__TileMaterial__) */
