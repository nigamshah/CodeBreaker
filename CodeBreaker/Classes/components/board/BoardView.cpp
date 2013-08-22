//
//  BoardView.cpp
//  CodeBreaker
//
//  Created by Nigam Shah on 8/16/13.
//
//

#include "BoardView.h"
bool BoardView::init() {
	if (!Component::init()) return false;
	this->setNode(CCNode::create());
	return true;
}

void BoardView::addCells(CCSpriteBatchNode* cells) {
	if (_cells && _cells->getParent() == _node) {
		_node->removeChild(_cells);
	}
	_cells = cells;
	_node->addChild(_cells);
}

bool BoardView::containsPoint(CCPoint point) {
	CCRect box = _cells->boundingBox();
	bool result = box.containsPoint(point);
	return result;
}