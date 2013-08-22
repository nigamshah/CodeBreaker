//
//  TileColor.h
//  CodeBreaker
//
//  Created by Nigam Shah on 8/22/13.
//
//

#ifndef __CodeBreaker__TileColor__
#define __CodeBreaker__TileColor__

#include "codebreaker.h"

namespace codebreaker {
	enum class TileColorType {
		Red,
		Green,
		Blue
	};

	class TileColor : public Component {
	private:

		map<TileColorType, ccColor3B> s_tileColorMap;
		TileColorType _type;

	public:

		CREATE_FUNC(TileColor);

		TileColorType getType() { return _type; }

		ccColor3B getColorValue() {
			ccColor3B colorValue = s_tileColorMap[_type];
			return colorValue;
		}

		void setType(TileColorType value) {
			if (_type == value) return;
			_type = value;
			sendLocalMessage("colorChanged");
		}
	};
}

#endif /* defined(__CodeBreaker__TileColor__) */
