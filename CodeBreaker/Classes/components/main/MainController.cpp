//
//  MainController.cpp
//  CodeBreaker
//
//  Created by Nigam Shah on 8/5/13.
//
//

#include "MainController.h"

#include "Tester.h"


using namespace codebreaker;

bool MainController::init() {
	if (!Component::init()) {
		return false;
	}

	// Main init stuff here

	return true;
}
void MainController::awake() {


}
void MainController::start() {
	_tester = *(new Tester());
	_tester.init();
}