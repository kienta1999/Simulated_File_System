// studio 18 - simple file factory definitions
#include "SimpleFileFactory.h"

AbstractFile* SimpleFileFactory::createFile(string filename) {
	string extension = filename.substr(filename.length() - 3, filename.length() - 1);
	if (extension == "txt") {
		return new TextFile(filename);
	}
	else if (extension == "img") {
		return new ImageFile(filename);
	}
	else {
		return nullptr;
	}
}