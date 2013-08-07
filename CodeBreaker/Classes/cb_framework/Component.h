//
//  Component.h
//  CodeBreaker
//
//  Created by Nigam Shah on 8/5/13.
//
//

#ifndef __CodeBreaker__Component__
#define __CodeBreaker__Component__

#include "cocos2d.h"
#include "Message.h"

namespace codebreaker {

	class Entity;

	typedef std::list<codebreaker::Component*> ComponentList;

	class Component : public cocos2d::CCObject {

	protected:
		typedef std::function<void (Message&)> MessageHandler;
		typedef std::list< std::pair<std::string, MessageHandler> >MessageHandlerList;

		std::map<std::string, MessageHandlerList*> _messageHandlerMap;

		void _subscribe(std::string message, MessageHandler messageHandler, std::string handlerToken);

		void _unsubscribe(std::string message, std::string handlerToken);

	public:
		CC_SYNTHESIZE(bool, _updateEnabled, UpdateEnabled);
		CC_SYNTHESIZE(bool, _messagesEnabled, MessagesEnabled);
		CC_SYNTHESIZE(Entity*, _entity, Entity);

		virtual bool init();
		virtual void awake() {};
		virtual void start() {};
		virtual void update(float dt) {};

		void sendMessage(std::string message);
		void sendMessage(std::string message, void* data);
		
		void handleMessage(std::string message, Message& messageObj);
	};
}

#endif /* defined(__CodeBreaker__Component__) */
