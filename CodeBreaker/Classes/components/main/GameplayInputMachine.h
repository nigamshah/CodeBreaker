//
//  GameplayInputMachine.h
//  CodeBreaker
//
//  Created by Nigam Shah on 8/15/13.
//
//

#ifndef __CodeBreaker__GameplayInputMachine__
#define __CodeBreaker__GameplayInputMachine__

#include "codebreaker.h"
#include "SceneManager.h"
#include "GameplayLayer.h"

namespace codebreaker {
	class InputStateReady : public State {

	public:

		virtual void onEnter(Message& message) {
			CCLog("InputStateReady.onEnter %s", message.getName().c_str());
		}

		virtual void onExit(Message& message) {
			CCLog("InputStateReady.onExit %s", message.getName().c_str());
		}

	};

	class InputStateDisabled : public State {

	public:

		virtual void onEnter(Message& message) {
			CCLog("InputStateDisabled.onEnter %s", message.getName().c_str());
		}

		virtual void onExit(Message& message) {
			CCLog("InputStateDisabled.onExit %s", message.getName().c_str());
		}

	};

	class InputStateDragging : public State {

	public:

		virtual void onEnter(Message& message) {
			CCLog("InputStateDragging.onEnter %s", message.getName().c_str());
		}

		virtual void onExit(Message& message) {
			CCLog("InputStateDragging.onExit %s", message.getName().c_str());
		}

	};

	class GameplayInputMachine : public StateMachine {
	private:
		GameplayLayer* _gameplayLayer;

	public:
		virtual bool init() {

			if (!StateMachine::init()) return false;

			State* disabled = _addState<InputStateDisabled>("disabled");
			State* ready = _addState<InputStateReady>("ready");
			State* dragging = _addState<InputStateDragging>("dragging");

			_addTransition(disabled, ready, "enableInput");
			_addTransition(ready, disabled, "disableInput");
			_addTransition(ready, dragging, "startDragging");
			_addTransition(dragging, ready, "stopDragging");

			return true;
		}


		virtual void start() {
			SceneManager* sceneMan = _entity->getComponentByType<SceneManager>();
			_gameplayLayer = static_cast<GameplayLayer*>(sceneMan->getGameplayScene()->getChildByTag(0));

			_setInitialState("disabled");
		}


		CREATE_FUNC(GameplayInputMachine);

	};
}

#endif /* defined(__CodeBreaker__GameplayInputMachine__) */
