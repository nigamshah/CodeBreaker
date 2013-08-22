//
//  Symbol.h
//  CodeBreaker
//
//  Created by Nigam Shah on 8/22/13.
//
//

#ifndef __CodeBreaker__Symbol__
#define __CodeBreaker__Symbol__

#include "codebreaker.h"
#include "GameSpriteComponent.h"

namespace codebreaker {

	enum class SymbolType {
		Ankh,
		Broom,
		Camel,
		Cat,
		Crab,
		Eye,
		Pyramid,
		Sarcophagus,
		Tree
	};

	class Symbol : public GameSpriteComponent {
	private:
		SymbolType _type;
		static map<SymbolType, string> s_symbolSpriteMap;
		void _setSprite();

	public:

		CREATE_FUNC(Symbol);
		virtual bool init();

		SymbolType getType() { return _type; }

		void setType(SymbolType value) {
			_type = value;
			_setSprite();
		}
	};
}

#endif /* defined(__CodeBreaker__Symbol__) */
