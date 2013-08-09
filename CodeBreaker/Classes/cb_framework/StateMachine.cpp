//
//  StateMachine.cpp
//  CodeBreaker
//
//  Created by Nigam Shah on 8/7/13.
//
//

#include "StateMachine.h"
#include <type_traits>

using namespace codebreaker;

StateMachine::~StateMachine() {
	_initialState = nullptr;
	_currentState = nullptr;
	for (State* st : _allStates) {
		st->release();
	}
	_allStates.clear();
}

bool StateMachine::init() {
	if (!Component::init()) return false;

	_initialState = nullptr;
	_currentState = nullptr;
	_allStates = *(new std::vector<State*>());
	return true;
}
void StateMachine::_setInitialState(std::string id) {
	for (State* st : _allStates) {
		if (st->getId().compare(id) == 0) {
			_initialState = st;
			break;
		}
	}
	if (_initialState) {
		_doTransition(_initialState, *(new Message("setInitialState", this, nullptr)));
	} else {
		cocos2d::CCLog("no state registered with id = %s", id.c_str());
	}
}

void StateMachine::_doTransition(State* pTargetState, Message& message) {
	if (!pTargetState || _currentState == pTargetState) return;

	if (_currentState) {
		_currentState->onExit(message);
		_currentState->release();
	}

	_currentState = pTargetState;
	_currentState->retain();
	_currentState->onEnter(message);
}
void StateMachine::_addTransition(State* pSourceState, State* pTargetState, std::string triggerName) {
	_subscribe(triggerName, std::bind(&StateMachine::_handleTrigger, this, std::placeholders::_1), triggerName);
	pSourceState->addTransition(triggerName, pTargetState);
}

void StateMachine::_handleTrigger(Message& message) {
	std::string triggerName = message.getName();
	State* pTargetState = _currentState->getTargetState(triggerName);
	if (pTargetState) {
		_doTransition(pTargetState, message);
	}
}
