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
		virtual bool init();
		CC_SYNTHESIZE_RETAIN(CCNode*, _node, Node);
		CREATE_FUNC(BoardView);

		void addCells(CCSpriteBatchNode* cells) {
			if (_cells && _cells->getParent() == _node) {
				_node->removeChild(_cells);
			}
			_cells = cells;
			_node->addChild(_cells);
		}

		bool containsPoint(CCPoint point) {
			CCRect box = _cells->boundingBox();
			bool result = box.containsPoint(point);
			return result;
		}
	};
}

#endif /* defined(__CodeBreaker__BoardView__) */
