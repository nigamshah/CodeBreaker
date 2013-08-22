//
//  TileMaterial.cpp
//  CodeBreaker
//
//  Created by Nigam Shah on 8/22/13.
//
//

#include "TileMaterial.h"
#include "TileColor.h"

map<TileMaterialType, string> TileMaterial::s_materialSpriteMap = {
	{ TileMaterialType::None, "tile_white.png"},
	{ TileMaterialType::Wood, "tile_white.png"},
	{ TileMaterialType::Bronze, "tile_white.png"},
	{ TileMaterialType::Silver, "tile_white.png"},
	{ TileMaterialType::Gold, "tile_white.png"}
};

TileMaterial::~TileMaterial() {
	_unsubscribe("colorChanged", "colorChanged");
}

bool TileMaterial::init() {
	if (!GameSpriteComponent::init()) return false;
	setType(TileMaterialType::Wood);
	_subscribe("colorChanged", bind(&TileMaterial::_colorize, this, _1), "colorChanged");
	return true;
}

void TileMaterial::_setSprite() {
	string fileName = s_materialSpriteMap[_type];
	GameSprite* sprite = GameSprite::gameSpriteWithSpriteFrameName(fileName.c_str());
	setGameSprite(sprite);
	sprite->setComponent(this);
}

void TileMaterial::_colorize(Message& msg) {
	TileColor* tileColor = static_cast<TileColor*>(msg.getSender());
	ccColor3B colorVal = tileColor->getColorValue();
	_gameSprite->setColor(colorVal);
}