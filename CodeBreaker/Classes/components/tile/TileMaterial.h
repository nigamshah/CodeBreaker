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

	private:
		static map<TileMaterialType, string> s_materialSpriteMap;

		TileMaterialType _type;
		void _setSprite();
		void _colorize(Message& msg);

	public:

		CREATE_FUNC(TileMaterial);
		~TileMaterial();
		
		virtual bool init();

		TileMaterialType getType() { return _type; }

		void setType(TileMaterialType value) {
			_type = value;
			_setSprite();
		}



	};
}

#endif /* defined(__CodeBreaker__TileMaterial__) */
