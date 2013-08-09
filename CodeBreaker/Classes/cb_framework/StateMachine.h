//
//  StateMachine.h
//  CodeBreaker
//
//  Created by Nigam Shah on 8/7/13.
//
//

#ifndef __CodeBreaker__StateMachine__
#define __CodeBreaker__StateMachine__

#include "Component.h"
#include "State.h"
#include "Message.h"

namespace codebreaker {

	class StateMachine : public Component {
	protected:

		std::vector<State*> _allStates;
		State* _initialState;// do I even need this?
		State* _currentState;

		template<class T>
		State* _addState(std::string id);
		void _addTransition(State* pSourceState, State* pTargetState, std::string triggerName);

		void _setInitialState(std::string id);
		void _handleTrigger(Message& message);
		void _doTransition(State* pTargetState, Message& message);


	public:


		
		~StateMachine();
		virtual bool init();
	};

	//////////////////////////////////////////////////////
	// template functions
	//////////////////////////////////////////////////////
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
}



#endif /* defined(__CodeBreaker__StateMachine__) */
