//
//  State.h
//  CodeBreaker
//
//  Created by Nigam Shah on 8/7/13.
//
//

#ifndef __CodeBreaker__State__
#define __CodeBreaker__State__

#include "cocos2d.h"
#include "Messenger.h"
#include "Message.h"

namespace codebreaker {
	class StateMachine;
	class State;
	
	class StateTransition {
	private:
		State* _sourceState; // weak
		State* _targetState; // weak
		std::string _triggerName;

	public:
		StateTransition(State* source, State* target, std::string triggerName) {
			_sourceState = source; // weak
			_targetState = target; // weak
			_triggerName = triggerName;
		}

		State* getSourceState() { return _sourceState; }
		State* getTargetState() { return _targetState; }
		std::string getTriggerName() { return _triggerName; }
		
	};
	
	class State : public cocos2d::CCObject {
	private:
		std::map<std::string, StateTransition> _transitions;

	protected:
		Messenger _messenger;

	public:

		CC_SYNTHESIZE(std::string, _id, Id);
		CC_SYNTHESIZE_READONLY(StateMachine*, _machine, Machine); // weak ref

		void setMachine(StateMachine* pMachine);
		
		bool addTransition(std::string triggerName, State* pTargetState);
		bool hasTransition(std::string triggerName);

		State* getTargetState(std::string triggerName);

		virtual void onEnter(Message& message) {}
		virtual void onExit(Message& message) {}

		virtual void handleMessage(std::string message, Message& messageObj);

	};


}
#endif /* defined(__CodeBreaker__State__) */
