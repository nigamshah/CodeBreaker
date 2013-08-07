//
//  Component.cpp
//  CodeBreaker
//
//  Created by Nigam Shah on 8/5/13.
//
//

#include "Component.h"
#include "Entity.h"

using namespace codebreaker;

bool Component::init() {
	_messageHandlerMap = *(new std::map<std::string, MessageHandlerList*>);
	_updateEnabled = false;
	_messagesEnabled = true;
	return true;
}

void Component::_subscribe(std::string message, MessageHandler messageHandler, std::string handlerToken) {

	_unsubscribe(message, handlerToken);
	
	MessageHandlerList* pList = _messageHandlerMap[message];
	if (!pList) {
		pList = new MessageHandlerList();
		_messageHandlerMap[message] = pList;
	}

	std::pair <std::string, MessageHandler> pr(handlerToken, messageHandler);

	pList->push_back(pr);
}

void Component::_unsubscribe(std::string message, std::string handlerToken) {
	MessageHandlerList* pList = _messageHandlerMap[message];
	if (!pList || pList->empty()) {
		return;
	}
	for (MessageHandlerList::iterator it = pList->begin(); it != pList->end(); it++) {
		std::pair<std::string, MessageHandler> pr = *it;
		if (handlerToken.compare(pr.first) == 0) {
			pList->erase(it);
		}
	}
}

void Component::sendMessage(std::string message) {
	sendMessage(message, nullptr);
}

void Component::sendMessage(std::string message, void* data) {
	Message* msgObj = new Message(message, this, data);
	_entity->sendMessage(message, msgObj);
	delete msgObj;
}

void Component::handleMessage(std::string message, Message& messageObj) {
	MessageHandlerList* pList = _messageHandlerMap[message];
	if (!pList || pList->empty()) {
		return;
	}
	for (auto& pr : *pList) {
		MessageHandler h = pr.second;
		h(messageObj);
	}
}




