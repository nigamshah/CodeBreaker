//
//  MainController.h
//  CodeBreaker
//
//  Created by Nigam Shah on 8/5/13.
//
//

#ifndef __CodeBreaker__MainController__
#define __CodeBreaker__MainController__

#include "codebreaker.h"
#include "Tester.h"

namespace codebreaker {
	class MainController		{
	private:
		static Tester s_tester;

	public:
		static bool init();

	};
}
#endif /* defined(__CodeBreaker__MainController__) */
