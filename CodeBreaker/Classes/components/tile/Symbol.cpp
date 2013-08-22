//
//  Symbol.cpp
//  CodeBreaker
//
//  Created by Nigam Shah on 8/22/13.
//
//

#include "Symbol.h"

map<SymbolType, string> Symbol::s_symbolSpriteMap = {
	{ SymbolType::Ankh, "ankh.png"},
	{ SymbolType::Broom, "broom.png"},
	{ SymbolType::Camel, "camel.png"},
	{ SymbolType::Cat, "cat.png"},
	{ SymbolType::Crab, "crab.png"},
	{ SymbolType::Eye, "eye.png"},
	{ SymbolType::Pyramid, "pyramid.png"},
	{ SymbolType::Sarcophagus, "sarcophagus.png"},
	{ SymbolType::Tree, "tree.png"}
};
bool Symbol::init() {
	if (!GameSpriteComponent::init()) return false;
	setType(SymbolType::Ankh);
	return true;
}
void Symbol::_setSprite() {
	string fileName = s_symbolSpriteMap[_type];
	GameSprite* sprite = GameSprite::gameSpriteWithSpriteFrameName(fileName.c_str());
	setGameSprite(sprite);
	sprite->setComponent(this);
}