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
	cocos2d::CCLog("msg received, message = %s", msg.getName().c_str());
	cocos2d::CCLog("data = %s", ((std::string*)msg.getData())->c_str());
}

void MainController::_awakeTests() {
	MessageHandler h = std::bind(&MainController::_testHandler, this, std::placeholders::_1);
	_subscribe("TestHandlerSystem", h, "testHandler");
}
void MainController::_startTests() {

	std::string* s = new std::string("Hello World");

	sendMessage("TestHandlerSystem", s);

	delete s;
	
}