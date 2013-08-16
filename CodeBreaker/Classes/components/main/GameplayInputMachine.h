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
		virtual void onEnter(Message& message);
		virtual void onExit(Message& message);
	};

	class InputStateDisabled : public State {
	public:
		virtual void onEnter(Message& message);
		virtual void onExit(Message& message);
	};

	class InputStateDragging : public State {

	public:
		virtual void onEnter(Message& message);
		virtual void onExit(Message& message);
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

		GameplayLayer* getGameplayLayer() { return _gameplayLayer; }
		CREATE_FUNC(GameplayInputMachine);

	};
}

//		// get location of touch as a CCPoint
//		touchLocation = pTouch->getLocation();

// iterate through the cells and determine which, if any cell was touched

//		for (int p = 0; p < 2; p++) {
//			player = (GameSprite *) _players->objectAtIndex(p);
//			if (player->boundingBox().containsPoint(tap)) {
//				player->setTouch(touch);
//			}
//		}

#endif /* defined(__CodeBreaker__GameplayInputMachine__) */
