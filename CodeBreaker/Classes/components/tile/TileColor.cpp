//
//  TileColor.cpp
//  CodeBreaker
//
//  Created by Nigam Shah on 8/22/13.
//
//

#include "TileColor.h"

map<TileColorType, ccColor3B> s_tileColorMap = {
	{ TileColorType::Red, ccc3(255, 0, 0)},
	{ TileColorType::Green, ccc3(0, 255, 0)},
	{ TileColorType::Blue, ccc3(0, 0, 255)}
};
