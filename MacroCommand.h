#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"
#include "AbstractParsingStrategy.h"

class MacroCommand : public AbstractCommand {
public:
	virtual ~MacroCommand() = default;
	MacroCommand(AbstractFileSystem*);
	virtual int execute(string);
	virtual void displayInfo();
	virtual void addCommand(AbstractCommand*);
	virtual void setParseStrategy(AbstractParsingStrategy*);
private:
	vector<AbstractCommand*> allCommands;
	AbstractParsingStrategy* parsingStrategy;
	AbstractFileSystem* fileSystem;
};