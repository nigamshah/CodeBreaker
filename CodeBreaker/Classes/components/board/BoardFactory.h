//
//  BoardFactory.h
//  CodeBreaker
//
//  Created by Nigam Shah on 8/9/13.
//
//

#ifndef __CodeBreaker__BoardFactory__
#define __CodeBreaker__BoardFactory__

#include "codebreaker.h"

namespace codebreaker {
	class BoardFactory : public Component {

	private:
		void _createCells();

	public:

		virtual void start();

		CREATE_FUNC(BoardFactory);

	};
}

#endif /* defined(__CodeBreaker__BoardFactory__) */
