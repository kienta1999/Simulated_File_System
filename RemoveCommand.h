#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"
using namespace std;

class RemoveCommand : public AbstractCommand {
public:
	static const int MAX_NAME_SIZE = 20;
	virtual ~RemoveCommand() = default;
	RemoveCommand(AbstractFileSystem*);
	virtual int execute(string);
	virtual void displayInfo();
private:
	AbstractFileSystem* fileSystem;
	AbstractFileFactory* fileFactory;
};