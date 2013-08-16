//
//  Messenger.h
//  CodeBreaker
//
//  Created by Nigam Shah on 8/16/13.
//
//

#ifndef __CodeBreaker__Messenger__
#define __CodeBreaker__Messenger__

#include "cocos2d.h"
#include "Message.h"

namespace codebreaker {

	class Entity; // forward declaration

	typedef std::function<void (Message&)> MessageHandler;
	typedef std::list< std::pair<std::string, MessageHandler> >MessageHandlerList;

	class Messenger {

	private:
		std::map<std::string, MessageHandlerList*> _messageHandlerMap;

	public:

		CC_SYNTHESIZE(bool, _messagesEnabled, MessagesEnabled);
		CC_SYNTHESIZE(cocos2d::CCObject*, _owner, Owner); // weak
		CC_SYNTHESIZE(Entity*, _entity, Entity); // weak

		Messenger();
		~Messenger(void);

		// Receiver methods
		void subscribe(std::string message, MessageHandler messageHandler, std::string handlerToken);
		void unsubscribe(std::string message, std::string handlerToken);
		void handleMessage(std::string message, Message& messageObj);

		// Sender methods
		void sendLocalMessage(std::string message);
		void sendLocalMessage(std::string message, std::string strData);
		void sendLocalMessage(std::string message, int intData);
		void sendLocalMessage(std::string message, void* data);

		void sendMessageToEntity(std::string eid, std::string message);
		void sendMessageToEntity(std::string eid, std::string message, std::string strData);
		void sendMessageToEntity(std::string eid, std::string message, int intData);
		void sendMessageToEntity(std::string eid, std::string message, void* data);

		void sendGlobalMessage(std::string message);
		void sendGlobalMessage(std::string message, std::string strData);
		void sendGlobalMessage(std::string message, int intData);
		void sendGlobalMessage(std::string message, void* data);

	};
}

#endif /* defined(__CodeBreaker__Messenger__) */
