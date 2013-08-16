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
#include "Messenger.h"

namespace codebreaker {

	class Entity;

	class Component : public cocos2d::CCObject {

	protected:
		Messenger* _messenger;

		void _subscribe(std::string message, MessageHandler messageHandler, std::string handlerToken);
		void _unsubscribe(std::string message, std::string handlerToken);

	public:
		CC_SYNTHESIZE(bool, _updateEnabled, UpdateEnabled);
		CC_SYNTHESIZE_READONLY(Entity*, _entity, Entity);

		void setEntity(Entity* pEnt);

		virtual bool init();
		virtual void awake() {};
		virtual void start() {};
		virtual void update(float dt) {};

		void setMessagesEnabled(bool value);
		bool getMessagesEnabled();

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
		
		virtual void handleMessage(std::string message, Message& messageObj);
	};
}

#endif /* defined(__CodeBreaker__Component__) */
