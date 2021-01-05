#pragma once
// declare AbstractFile here. As all methods are virtual and will not be defined, no .cpp file is necessary
#include <vector>
#include <string>
#include <iostream>
using namespace std;
//Not need to include AbstractFileVisitor -> avoid circular include

enum struct status { success, invalidInput = 1, noAppend = 2, fileInMap = 3, fileNotOpen = 4, fileIsOpen = 5, wrongPassword = 6, createFailed = 7, duplicatedCommand
 = 8, lsFailed= 9, cpFailed = 10};

//we dont care about full declaration. Forward declaration
class AbstractFileVisitor;

class AbstractFile {
public:
	virtual vector<char> read() = 0;
	virtual int write(vector<char>) = 0;
	virtual int append(vector<char>) = 0;
	virtual unsigned int getSize() = 0;
	virtual string getName() = 0;
	virtual string getType() = 0;
	virtual ~AbstractFile() = default;
	virtual void accept(AbstractFileVisitor*) = 0;
	virtual AbstractFile* clone(string newName) = 0;
};
