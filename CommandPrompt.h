#pragma once

#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"
#include <iterator>
#include <map> 
#include <sstream>

class CommandPrompt {
public:
	CommandPrompt();
	~CommandPrompt() = default;
	void setFileSystem(AbstractFileSystem*);
	void setFileFactory(AbstractFileFactory*);
	int addCommand(string, AbstractCommand*);
	int run();
private:
	map<string, AbstractCommand*> commandObjects;
	AbstractFileSystem* fileSystem;
	AbstractFileFactory* fileFactory;
protected:
	void listCommands();
	string prompt();
};