//
//  GameplayInputMachine.cpp
//  CodeBreaker
//
//  Created by Nigam Shah on 8/15/13.
//
//

#include "GameplayInputMachine.h"

////////////////////////////////////////
//	InputStateReady
////////////////////////////////////////
void InputStateReady::onEnter(Message& message) {
	CCLog("InputStateReady.onEnter %s", message.getName().c_str());
	GameplayLayer* layer = static_cast<GameplayInputMachine*>(_machine)->getGameplayLayer();
	layer->setTouchEnabled(true);
}

void InputStateReady::onExit(Message& message) {
	CCLog("InputStateReady.onExit %s", message.getName().c_str());
	GameplayLayer* layer = static_cast<GameplayInputMachine*>(_machine)->getGameplayLayer();
	layer->setTouchEnabled(false);
}

////////////////////////////////////////
//	InputStateDisabled
////////////////////////////////////////
void InputStateDisabled::onEnter(Message& message) {
	CCLog("InputStateDisabled.onEnter %s", message.getName().c_str());
	GameplayLayer* layer = static_cast<GameplayInputMachine*>(_machine)->getGameplayLayer();
	layer->setTouchEnabled(false);
}

void InputStateDisabled::onExit(Message& message) {
	CCLog("InputStateDisabled.onExit %s", message.getName().c_str());
	GameplayLayer* layer = static_cast<GameplayInputMachine*>(_machine)->getGameplayLayer();
	layer->setTouchEnabled(false);
}

////////////////////////////////////////
//	InputStateDragging
////////////////////////////////////////
void InputStateDragging::onEnter(Message& message) {
	CCLog("InputStateDragging.onEnter %s", message.getName().c_str());
	GameplayLayer* layer = static_cast<GameplayInputMachine*>(_machine)->getGameplayLayer();
	layer->setTouchEnabled(true);
}
void InputStateDragging::onExit(Message& message) {
	CCLog("InputStateDragging.onExit %s", message.getName().c_str());
	GameplayLayer* layer = static_cast<GameplayInputMachine*>(_machine)->getGameplayLayer();
	layer->setTouchEnabled(false);
}