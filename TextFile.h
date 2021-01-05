#pragma once
#include "AbstractFile.h"

// TextFile declaration goes here
class TextFile: public AbstractFile {
public:
	TextFile(string fileName);
	virtual vector<char> read();
	virtual int write(vector<char>);
	virtual int append(vector<char>);
	virtual unsigned int getSize();
	virtual string getName();
	virtual string getType();
	virtual void accept(AbstractFileVisitor*);
	virtual AbstractFile* clone(string newName);
private:
	string name;
	vector<char> contents;
};