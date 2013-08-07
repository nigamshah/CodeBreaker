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

namespace codebreaker {

	class StateMachine : public Component {
	protected:

		std::vector<State*> _allStates;
		State* _initialState;
		State* _currentState;


//		State* _addState(std::string stateName);
		template<class T>
		State* _addState(std::string id);

		void _addTransition(State* pSourceState, std::string triggerName, State* pTargetState);

//		void _handleTrigger(CCObject* evt);
		void _doTransition(State* pTargetState);

	public:

		~StateMachine();
		virtual bool init();
	};
}


#endif /* defined(__CodeBreaker__StateMachine__) */
