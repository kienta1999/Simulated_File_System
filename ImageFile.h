#pragma once
#include "AbstractFile.h"
// Image file class declaration here
class ImageFile : public AbstractFile {
public:
	ImageFile(string fileName);
	virtual vector<char> read();
	virtual int write(vector<char>);
	virtual int append(vector<char>);
	virtual unsigned int getSize();
	virtual string getName();
	virtual void accept(AbstractFileVisitor*);
private:
	string name;
	vector<char> contents;
	char size;
	int getIndex(int x, int y);
};