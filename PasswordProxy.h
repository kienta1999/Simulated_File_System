#pragma once
#include "AbstractFile.h"

class PasswordProxy : public AbstractFile {
public:
	PasswordProxy(AbstractFile*, string);
	virtual ~PasswordProxy();
	virtual vector<char> read();
	virtual int write(vector<char>);
	virtual int append(vector<char>);
	virtual unsigned int getSize();
	virtual string getName();
	virtual string getType();
	virtual void accept(AbstractFileVisitor*);
	virtual AbstractFile* clone(string newName);
private:
	AbstractFile* protectedFile;
	string password;
protected:
	string passwordPrompt();
	bool passwordCheck(string);
};