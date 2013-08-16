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