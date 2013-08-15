//
//  GameplayInputMachine.cpp
//  CodeBreaker
//
//  Created by Nigam Shah on 8/15/13.
//
//

#include "GameplayInputMachine.h"

void InputStateReady::onEnter(Message& message) {
	CCLog("InputStateReady.onEnter %s", message.getName().c_str());
}

void InputStateReady::onExit(Message& message) {
	CCLog("InputStateReady.onExit %s", message.getName().c_str());
}

void InputStateDisabled::onEnter(Message& message) {
	CCLog("InputStateDisabled.onEnter %s", message.getName().c_str());
}

void InputStateDisabled::onExit(Message& message) {
	CCLog("InputStateDisabled.onExit %s", message.getName().c_str());
}

void InputStateDragging::onEnter(Message& message) {
	CCLog("InputStateDragging.onEnter %s", message.getName().c_str());
}
void InputStateDragging::onExit(Message& message) {
	CCLog("InputStateDragging.onExit %s", message.getName().c_str());
}