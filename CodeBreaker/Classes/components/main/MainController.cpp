//
//  MainController.cpp
//  CodeBreaker
//
//  Created by Nigam Shah on 8/5/13.
//
//

#include "MainController.h"

#include "FileReader.h"
#include "document.h"

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
	string fileContents = FileReader::FileReaderText("settings_global.json");
	CCLog("contents of file = %s", fileContents.c_str());

	rapidjson::Document d;
	d.Parse<0>(fileContents.c_str());

	CCLog("test1 = %s", d["testObject"]["test2"].GetString());

	const rapidjson::Value& arr = d["testArray"];

	assert(arr.IsArray());

	for (rapidjson::SizeType i = 0; i < arr.Size(); i++) {
		if (arr[i].IsInt()) {
			CCLog("value + 10 = %i", arr[i].GetInt() + 10);
		} else if (arr[i].IsString()) {
			CCLog("value is a string = %s", arr[i].GetString());
		} else {
			CCLog("value type char = %hhd", static_cast<const char>(arr[i].GetType()));
			CCLog("value type i = %i", static_cast<int>(arr[i].GetType()));
//			CCLog("value is a string AND = %s", arr[3]["someKey"].GetString());
		}
	}

}