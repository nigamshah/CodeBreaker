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

bool StateMachine::init() {
	if (!Component::init()) return false;

	_initialState = nullptr;
	_currentState = nullptr;
	_allStates = *(new std::vector<State*>());
	return true;
}

void StateMachine::_doTransition(State* pTargetState) {
	if (!pTargetState || _currentState == pTargetState) return;

	if (_currentState) {
		_currentState->onExit();
		_currentState->release();
	}

	_currentState = pTargetState;
	_currentState->retain();
	_currentState->onEnter();
}

template<class T>
State* StateMachine::_addState(std::string id) {
	static_assert(std::is_base_of<State, T>::value, "trying to add a state type that doesn't inherit from State");

	State* pState = new T();
	pState->retain();
	pState->setId(id);
	pState->setMachine(this);
	_allStates.push_back(pState);
	return pState;
}