//
//  BoardView.h
//  CodeBreaker
//
//  Created by Nigam Shah on 8/16/13.
//
//

#ifndef __CodeBreaker__BoardView__
#define __CodeBreaker__BoardView__

#include "codebreaker.h"

namespace codebreaker {
	class BoardView : public Component {
	private:
		CCSpriteBatchNode* _cells;

	public:

		CC_SYNTHESIZE_RETAIN(CCNode*, _node, Node);
		CREATE_FUNC(BoardView);
		virtual bool init();
		
		void addCells(CCSpriteBatchNode* cells);

		bool containsPoint(CCPoint point);
	};
}

#endif /* defined(__CodeBreaker__BoardView__) */
