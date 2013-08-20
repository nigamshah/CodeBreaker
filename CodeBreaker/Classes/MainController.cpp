//
//  MainController.cpp
//  CodeBreaker
//
//  Created by Nigam Shah on 8/5/13.
//
//

#include "MainController.h"
#include "ServiceLocator.h"
#include "Tester.h"
#include "EntityManager.h"

using namespace codebreaker;

Tester MainController::s_tester;

bool MainController::init() {

	// Main init stuff here

	ServiceLocator::init();

	bool configSuccess = ServiceLocator::getConfig()->init();
	CCLog("Config success = %i", configSuccess);

	EntityManager::createEntity("main", "main");

	s_tester.init();

	return true;
}
