//
//  Message.h
//  CodeBreaker
//
//  Created by Nigam Shah on 8/6/13.
//
//

#ifndef __CodeBreaker__Message__
#define __CodeBreaker__Message__

#include "cocos2d.h"

namespace codebreaker {

	class Component;

	class Message {
	private:
		std::string _name;
		Component* _sender;
		void* _data;

	public:

		Message(std::string name, Component* sender, void* data) {
			_name = name;
			_sender = sender;
			_data = data;
		}
		~Message() {
			_name = "";
			_sender = nullptr;
			_data = nullptr;
		}

		std::string getName() const { return _name; }
		Component* getSender() const { return _sender; }
		void* getData() const { return _data; }

	};
}

#endif /* defined(__CodeBreaker__Message__) */
