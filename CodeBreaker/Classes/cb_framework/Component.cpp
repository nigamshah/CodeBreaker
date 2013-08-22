//
//  Component.cpp
//  CodeBreaker
//
//  Created by Nigam Shah on 8/5/13.
//
//

#include "Component.h"
#include "Entity.h"
#include "EntityManager.h"

using namespace codebreaker;

bool Component::init() {
	_messenger.init();
	_messenger.setOwner(this);
	_updateEnabled = false;
	return true;
}
void Component::setEntity(Entity* pEnt) {
	_entity = pEnt;
	_messenger.setEntity(_entity);
}

void Component::setMessagesEnabled(bool value) {
	_messenger.setMessagesEnabled(value);
}
bool Component::getMessagesEnabled() {
	return _messenger.getMessagesEnabled();
}

void Component::_subscribe(std::string message, MessageHandler messageHandler, std::string handlerToken) {
	_messenger.subscribe(message, messageHandler, handlerToken);
}

void Component::_unsubscribe(std::string message, std::string handlerToken) {
	_messenger.unsubscribe(message, handlerToken);
}

void Component::sendLocalMessage(std::string message) {
	_messenger.sendLocalMessage(message);
}
void Component::sendLocalMessage(std::string message, std::string strData) {
	_messenger.sendLocalMessage(message, strData);
}
void Component::sendLocalMessage(std::string message, int intData) {
	_messenger.sendLocalMessage(message, intData);
}

void Component::sendLocalMessage(std::string message, void* data) {
	_messenger.sendLocalMessage(message, data);
}

void Component::sendMessageToEntity(std::string eid, std::string message) {
	_messenger.sendMessageToEntity(eid, message);
}
void Component::sendMessageToEntity(std::string eid, std::string message, std::string strData) {
	_messenger.sendMessageToEntity(eid, message, strData);
}
void Component::sendMessageToEntity(std::string eid, std::string message, int intData) {
	_messenger.sendMessageToEntity(eid, message, intData);
}
void Component::sendMessageToEntity(std::string eid, std::string message, void* data) {
	_messenger.sendMessageToEntity(eid, message, data);
}

void Component::sendGlobalMessage(std::string message) {
	_messenger.sendGlobalMessage(message);
}
void Component::sendGlobalMessage(std::string message, std::string strData) {
	_messenger.sendGlobalMessage(message, strData);
}
void Component::sendGlobalMessage(std::string message, int intData) {
	_messenger.sendGlobalMessage(message, intData);
}

void Component::sendGlobalMessage(std::string message, void* data) {
	_messenger.sendGlobalMessage(message, data);
}

void Component::handleMessage(std::string message, Message& messageObj) {
	_messenger.handleMessage(message, messageObj);
}




