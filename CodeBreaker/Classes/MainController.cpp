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

	// first init the config
	bool configSuccess = ServiceLocator::getConfig().init();

	bool randomSuccess = ServiceLocator::getRandomGenerator().init();

	// init the entity factories
	bool entityFactorySuccess = ServiceLocator::getEntityFactory().init();

	bool testerSuccess = s_tester.init();

	EntityManager::createEntity("main", "main");

	

	return configSuccess && entityFactorySuccess && testerSuccess;
}
