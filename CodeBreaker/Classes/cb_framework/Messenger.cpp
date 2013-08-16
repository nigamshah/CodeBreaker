//
//  Messenger.cpp
//  CodeBreaker
//
//  Created by Nigam Shah on 8/16/13.
//
//

#include "Messenger.h"
#include "Message.h"
#include "EntityManager.h"

using namespace codebreaker;

Messenger::Messenger() {
	_messageHandlerMap = *(new std::map<std::string, MessageHandlerList*>);
	_messagesEnabled = true;
	_owner = nullptr;
	_entity = nullptr;
}

void Messenger::subscribe(std::string message, MessageHandler messageHandler, std::string handlerToken) {

	unsubscribe(message, handlerToken);

	MessageHandlerList* pList = _messageHandlerMap[message];
	if (!pList) {
		pList = new MessageHandlerList();
		_messageHandlerMap[message] = pList;
	}

	std::pair <std::string, MessageHandler> pr(handlerToken, messageHandler);

	pList->push_back(pr);
}

void Messenger::unsubscribe(std::string message, std::string handlerToken) {
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
void Messenger::handleMessage(std::string message, Message& messageObj) {
	MessageHandlerList* pList = _messageHandlerMap[message];
	if (!pList || pList->empty()) {
		return;
	}
	for (auto& pr : *pList) {
		MessageHandler h = pr.second;
		h(messageObj);
	}
}

void Messenger::sendLocalMessage(std::string message) {
	sendLocalMessage(message, nullptr);
}
void Messenger::sendLocalMessage(std::string message, std::string strData) {
	std::string* pStrObj = new std::string(strData);
	sendLocalMessage(message, pStrObj);
	delete pStrObj;
}
void Messenger::sendLocalMessage(std::string message, int intData) {
	int* pIntData = new int(intData);
	sendLocalMessage(message, pIntData);
	delete pIntData;
}

void Messenger::sendLocalMessage(std::string message, void* data) {
	Message* msgObj = new Message(message, _owner, data);
	_entity->sendLocalMessage(message, msgObj);
	delete msgObj;
}

void Messenger::sendMessageToEntity(std::string eid, std::string message) {
	sendMessageToEntity(eid, message, nullptr);
}
void Messenger::sendMessageToEntity(std::string eid, std::string message, std::string strData) {
	std::string* pStrObj = new std::string(strData);
	sendMessageToEntity(eid, message, pStrObj);
	delete pStrObj;
}
void Messenger::sendMessageToEntity(std::string eid, std::string message, int intData) {
	int* pIntData = new int(intData);
	sendMessageToEntity(eid, message, pIntData);
	delete pIntData;
}
void Messenger::sendMessageToEntity(std::string eid, std::string message, void* data) {
	EntityManager::sendMessageToEntity(eid, message, _owner, data);
}

void Messenger::sendGlobalMessage(std::string message) {
	sendGlobalMessage(message, nullptr);
}
void Messenger::sendGlobalMessage(std::string message, std::string strData) {
	std::string* pStrObj = new std::string(strData);
	sendGlobalMessage(message, pStrObj);
	delete pStrObj;
}
void Messenger::sendGlobalMessage(std::string message, int intData) {
	int* pIntData = new int(intData);
	sendGlobalMessage(message, pIntData);
	delete pIntData;
}

void Messenger::sendGlobalMessage(std::string message, void* data) {
	EntityManager::sendMessageToAllEntities(message, _owner, data);
}