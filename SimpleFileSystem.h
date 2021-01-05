#pragma once
#include "AbstractFileSystem.h"
#include "TextFile.h"
#include "ImageFile.h"

// declaration of SimpleFileSystem class goes here
class SimpleFileSystem : public AbstractFileSystem {
public:
	virtual int addFile(string filename, AbstractFile* abstractFile);
	virtual int deleteFile(string filename);
	virtual AbstractFile* openFile(string filename);
	virtual int closeFile(AbstractFile* abstractFile);
	virtual set<string> getFileNames();
private:
	map<string, AbstractFile*> files;
	set<AbstractFile*> openFiles; 
};
