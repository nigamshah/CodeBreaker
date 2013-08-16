//
//  Entity.h
//  CodeBreaker
//
//  Created by Nigam Shah on 8/5/13.
//
//

#ifndef __CodeBreaker__Entity__
#define __CodeBreaker__Entity__

#include "cocos2d.h"
#include "Component.h"
#include "TypeUtils.h"



namespace codebreaker {

	typedef std::list<codebreaker::Component*> ComponentList;

	class Entity : public cocos2d::CCObject {
	private:

		std::map<std::string, ComponentList*> _componentsByType;

		void _deleteAllComponents();

	public:

		static Entity* createWithEid(std::string eid);

		CC_SYNTHESIZE(std::string, _eid, Eid);
		CC_SYNTHESIZE(std::string, _templateId, TemplateId);

		~Entity(void);

		bool init();
		void start();
		void update(float dt);

		Component* addComponentToEntity(Component* pComponent);
		void removeComponent(Component* pComponent);

		template <class T> ComponentList* getComponentsByType();
		ComponentList* getComponentsByType(std::string typeName);

		template <class T> T* getComponentByType();

		template <class T> bool hasComponentOfType();
		bool hasComponentOfType(std::string typeName);

		void sendLocalMessage(std::string message, Message* messageObj);



		// preprocessor macro for "static create()"
		CREATE_FUNC(Entity);

	};

	//////////////////////////////////////////////
	//	Template methods
	//////////////////////////////////////////////

	template <class T>
	ComponentList* Entity::getComponentsByType() {
		std::string typeName = TypeUtils::demangledTypeName(typeid(T).name());
		return getComponentsByType(typeName);
	}
	template <class T>
	T* Entity::getComponentByType() {
		std::string typeName = TypeUtils::demangledTypeName(typeid(T).name());
		ComponentList* list = getComponentsByType(typeName);
		if (list->empty()) return nullptr;
		return static_cast<T*>(list->front());
	}


	template <class T>
	bool Entity::hasComponentOfType() {
		std::string typeName = TypeUtils::demangledTypeName(typeid(T).name());
		return hasComponentOfType(typeName);
	}
}

#endif /* defined(__CodeBreaker__Entity__) */
