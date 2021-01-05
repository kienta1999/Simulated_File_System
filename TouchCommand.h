#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"
#include "PasswordProxy.h"

class TouchCommand : public AbstractCommand {
public:
	virtual ~TouchCommand() = default;
	TouchCommand(AbstractFileSystem*, AbstractFileFactory*);
	virtual int execute(string);
	virtual void displayInfo();
private:
	AbstractFileSystem* fileSystem;
	AbstractFileFactory* fileFactory;
};