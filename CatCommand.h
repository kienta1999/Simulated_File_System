#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"
#include "PasswordProxy.h"

class CatCommand : public AbstractCommand {
public:
	virtual ~CatCommand() = default;
	CatCommand(AbstractFileSystem*);
	virtual int execute(string);
	virtual void displayInfo();
private:
	AbstractFileSystem* fileSystem;
	AbstractFileFactory* fileFactory;
};
