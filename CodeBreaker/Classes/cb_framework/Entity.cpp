//
//  Entity.cpp
//  CodeBreaker
//
//  Created by Nigam Shah on 8/5/13.
//
//

#include "Entity.h"

using namespace codebreaker;

//////////////////////////////
// static
//////////////////////////////

Entity* Entity::createWithEid(std::string eid) {
	Entity* ent = Entity::create();
	ent->setEid(eid);
	ent->setTemplateId("");
	return ent;
}

//////////////////////////////
// initialization
//////////////////////////////

bool Entity::init() {
	_componentsByType = *(new std::map<std::string, ComponentList*>);
	return true;
}


//////////////////////////////
// Component management
//////////////////////////////

Component* Entity::addComponentToEntity(Component* pComponent) {
	std::string typeName = TypeUtils::demangledTypeName(typeid(*pComponent).name());

	ComponentList* pCompList = getComponentsByType(typeName);
	if (!pCompList) {
		pCompList = new ComponentList();
		_componentsByType[typeName] = pCompList;
	}

	pComponent->setEntity(this);
	pComponent->retain();
	pCompList->push_back(pComponent);
	pComponent->awake();

	return pComponent;
}

void Entity::start() {
	for (auto& pr : _componentsByType) {
		for (Component* comp : *pr.second) {
			comp->start();
		}
	}
}
void Entity::update(float dt) {
	for (auto& pr : _componentsByType) {
		for (Component* comp : *pr.second) {
			if (comp->getUpdateEnabled()) {
				comp->update(dt);
			}
		}
	}
}

void Entity::removeComponent(Component* pComponent) {
	// TODO
	cocos2d::CCLog("Entity::removeComponent is a TODO");
}

ComponentList* Entity::getComponentsByType(std::string typeName) {
	ComponentList* result = _componentsByType[typeName];
	return result;
}
bool Entity::hasComponentOfType(std::string typeName) {
	ComponentList* pCompList = getComponentsByType(typeName);
	bool result = !pCompList->empty();
	return result;
}

//////////////////////////////
// Messages
//////////////////////////////

void Entity::sendLocalMessage(std::string message, Message* messageObj) {
	for (auto& pr : _componentsByType) {
		for (Component* comp : *pr.second) {
			if (comp->getMessagesEnabled()) {
				comp->handleMessage(message, *messageObj);
			}
		}
	}
}

//////////////////////////////
// disposal / cleanup
//////////////////////////////

Entity::~Entity() {
	_deleteAllComponents();
}

void Entity::_deleteAllComponents() {
	cocos2d::CCLog("Entity, id = %s, _deleteAllComponents", _eid.c_str());
	// go through all components and safe release
	_componentsByType.clear();
}
