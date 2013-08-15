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


using namespace codebreaker;

bool MainController::init() {
	if (!Component::init()) {
		return false;
	}

	// Main init stuff here

	ServiceLocator::init();

	bool configSuccess = ServiceLocator::getConfig()->init();
	CCLog("Config success = %i", configSuccess);


	return true;
}
void MainController::awake() {


}
void MainController::start() {
	_tester = new Tester();
	_tester->init();
}