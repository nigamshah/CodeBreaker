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
		cocos2d::CCObject* _sender;
		void* _data;

	public:

		Message(std::string name, cocos2d::CCObject* sender, void* data) {
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
		cocos2d::CCObject* getSender() const { return _sender; }
		void* getData() const { return _data; }
		template<class T>
		T getData() {
			T result = static_cast<T>(_data);
			return result;
		}

	};
}

#endif /* defined(__CodeBreaker__Message__) */
