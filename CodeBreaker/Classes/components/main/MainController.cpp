//
//  MainController.cpp
//  CodeBreaker
//
//  Created by Nigam Shah on 8/5/13.
//
//

#include "MainController.h"
using namespace codebreaker;

bool MainController::init() {
	if (!Component::init()) {
		return false;
	}

	// Main init stuff here

	return true;
}
void MainController::awake() {
	_awakeTests();

}
void MainController::start() {
	_startTests();
}

void MainController::_testHandler(Message& msg) {
}

void MainController::_awakeTests() {
}
void MainController::_startTests() {

}