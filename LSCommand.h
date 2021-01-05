#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"
#include <iomanip> 
using namespace std;

class LSCommand : public AbstractCommand {
public:
	static const int MAX_NAME_SIZE = 20;
	virtual ~LSCommand() = default;
	LSCommand(AbstractFileSystem*);
	virtual int execute(string);
	virtual void displayInfo();
private:
	AbstractFileSystem* fileSystem;
	AbstractFileFactory* fileFactory;
};