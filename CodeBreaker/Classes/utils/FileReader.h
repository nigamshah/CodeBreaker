//
//  FileReader.h
//  CodeBreaker
//
//  Created by Nigam Shah on 8/12/13.
//
//

#ifndef CodeBreaker_FileReader_h
#define CodeBreaker_FileReader_h

#include "cocos2d.h"

using namespace cocos2d;
using namespace std;

namespace codebreaker {
	class FileReader {
	public:

		static string FileReaderText(string pFileName) {
			// Initialize variables needed
			unsigned long fileSize = 0;
			unsigned char * fileContents = NULL;
			string fullPath;
			string contents;

			// Get absolute path of file
			fullPath = CCFileUtils::sharedFileUtils()->fullPathForFilename(pFileName.c_str());

			// Get data of file
			fileContents = CCFileUtils::sharedFileUtils()->getFileData(fullPath.c_str(), "r", &fileSize);
			contents.append((char *) fileContents);

			// For testing purposes
			CCLog("[ NOTICE ] Finished opening file: %s", pFileName.c_str());

			return contents;
		};

	};
}


#endif
