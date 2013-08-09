//
//  GameModeMachine.h
//  CodeBreaker
//
//  Created by Nigam Shah on 8/9/13.
//
//

#ifndef __CodeBreaker__GameModeMachine__
#define __CodeBreaker__GameModeMachine__

#include "codebreaker.h"

namespace codebreaker {

	class MenuState : public State {

	public:

		virtual void onEnter(Message& message) {
			CCLog("Menu.onEnter %s", message.getName().c_str());
		}

		virtual void onExit(Message& message) {
			CCLog("Menu.onExit %s", message.getName().c_str());
		}

	};

	class GameplayState : public State {

	public:
		virtual void onEnter(Message& message) {
			CCLog("Gameplay.onEnter %s", message.getName().c_str());
			_machine->sendLocalMessage("switchScene", "Game");
		}

		virtual void onExit(Message& message) {
			CCLog("Gameplay.onExit %s", message.getName().c_str());
		}


	};

	class GameModeMachine : public StateMachine {

	public:
		virtual bool init() {

			if (!StateMachine::init()) return false;

			State* menu = _addState<MenuState>("menu");
			State* gameplay = _addState<GameplayState>("gameplay");

			_addTransition(menu, gameplay, "startGame");
			_addTransition(gameplay, menu, "goMenu");

			return true;
		}


		virtual void start() {
			_setInitialState("menu");
		}

		CREATE_FUNC(GameModeMachine);

	};


}

#endif /* defined(__CodeBreaker__GameModeMachine__) */
