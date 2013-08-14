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
	class MainController : public Component {
	private:
		Tester _tester;

	public:

		virtual bool init();

		virtual void start();
		virtual void awake();
		//virtual void update(float dt);


		CREATE_FUNC(MainController);
	};
}
#endif /* defined(__CodeBreaker__MainController__) */
