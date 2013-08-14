//
//  ServiceLocator.cpp
//  CodeBreaker
//
//  Created by Nigam Shah on 8/14/13.
//
//

#include "ServiceLocator.h"

Config* ServiceLocator::s_config;

void ServiceLocator::init()  {
	s_config = new Config();
}