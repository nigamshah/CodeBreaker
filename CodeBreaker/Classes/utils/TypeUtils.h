//
//  TypeUtils.h
//  CodeBreaker
//
//  Created by Nigam Shah on 8/5/13.
//
//

#ifndef __CodeBreaker__TypeUtils__
#define __CodeBreaker__TypeUtils__

#include <cxxabi.h>
class TypeUtils
{

public:
	static const std::string demangledTypeName(const char* name) {
		int status = -4;
		char* res = abi::__cxa_demangle(name, NULL, NULL, &status);
		const char* const demangled_name = (status==0)?res:name;
		std::string ret_val(demangled_name);
		free(res);
		return ret_val;
	}

};

#endif /* defined(__CodeBreaker__TypeUtils__) */
