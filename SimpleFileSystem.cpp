// define methods of SimpleFileSystem class here
#include "SimpleFileSystem.h"

int SimpleFileSystem::addFile(string filename, AbstractFile* abstractFile) {
	if (files.count(filename) || abstractFile == nullptr) {
		return static_cast<int>(status::fileInMap);
	}
	files[filename] = abstractFile;
	return static_cast<int>(status::success);
}

AbstractFile* SimpleFileSystem::openFile(string filename) {
	if (files.count(filename) && !openFiles.count(files[filename])) {
		openFiles.insert(files[filename]);
		return files[filename];
	}
	else {
		return nullptr;
	}
}

int SimpleFileSystem::closeFile(AbstractFile* abstractFile) {
	if (openFiles.count(abstractFile)) {
		openFiles.erase(abstractFile);
		return static_cast<int>(status::success);
	}
	else {
		return static_cast<int>(status::fileNotOpen);
	}
}

int SimpleFileSystem::deleteFile(string filename) {
	if (!files.count(filename)) {
		return static_cast<int>(status::invalidInput);
	}
	else {
		if (openFiles.count(files[filename])) {
			return static_cast<int>(status::fileIsOpen);
		}
		else {
			delete files[filename];
			files.erase(filename);
			return static_cast<int>(status::success);
		}
	}
}

set<string> SimpleFileSystem::getFileNames() {
	set <string> filesName;
	for (auto itr = files.begin(); itr != files.end(); itr++) {
		filesName.insert(itr->first);
	}
	return filesName;
}