//
//  State.cpp
//  CodeBreaker
//
//  Created by Nigam Shah on 8/7/13.
//
//

#include "State.h"
#include "StateMachine.h"

using namespace codebreaker;

State::State() {
	_transitions = *(new std::map<std::string, StateTransition*>);
	_messenger = new Messenger();
}
State::~State() {
	_id = "";
	_machine = nullptr;
	_transitions.clear();
}

#include "Component.h"
void State::setMachine(StateMachine* pMachine) {
	_machine = pMachine;

	_messenger->setOwner(_machine);
	_messenger->setEntity(_machine->getEntity());

}
bool State::addTransition(std::string triggerName, State* pTargetState) {
	if (pTargetState == nullptr) {
		CCLOG("ERROR: Target state is null");
		return false;
	}
	if (triggerName.empty()) {
		CCLOG("ERROR: triggerName is blank");
		return false;
	}

	_transitions[triggerName] = new StateTransition(this, pTargetState, triggerName);

	return true;
}

bool State::hasTransition(std::string triggerName) {
	auto it = _transitions.find(triggerName);
	bool result = (it != _transitions.end());
	return result;
}

State* State::getTargetState(std::string triggerName) {
	State* result = nullptr;
	auto it = _transitions.find(triggerName);
	if (it != _transitions.end()) {
		StateTransition* trans = it->second;
		result = trans->getTargetState();
	}
	return result;
}
void State::handleMessage(std::string message, Message& messageObj) {
	_messenger->handleMessage(message, messageObj);
}
