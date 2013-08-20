//
//  StringUtils.h
//  CodeBreaker
//
//  Created by Nigam Shah on 8/14/13.
//
//

#ifndef __CodeBreaker__StringUtils__
#define __CodeBreaker__StringUtils__

#include "cocos2d.h"

namespace codebreaker {
	class StringUtils {

	public:

		static std::vector<std::string> split(const std::string &s, char delim) {
			std::vector<std::string> elems;
			std::stringstream ss(s);
			std::string item;
			while (std::getline(ss, item, delim)) {
				elems.push_back(item);
			}
			return elems;
		}

		template <class T>
		static std::string to_string (const T& t)
		{
			std::stringstream ss;
			ss << t;
			return ss.str();
		}
	};
}


#endif /* defined(__CodeBreaker__StringUtils__) */
