#pragma once
// declaration of the interface all file systems provide goes here
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <set>
#include "AbstractFile.h"
using namespace std;

class AbstractFileSystem {
public:
	virtual int addFile(string filename, AbstractFile* abstractFile) = 0;
	virtual int deleteFile(string filename) = 0;
	virtual AbstractFile* openFile(string filename) = 0;
	virtual int closeFile(AbstractFile* abstractFile) = 0;
};
