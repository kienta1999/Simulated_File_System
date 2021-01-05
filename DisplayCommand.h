#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"
#include "BasicDisplayVisitor.h"
#include "MetadataDisplayVisitor.h"

class DisplayCommand : public AbstractCommand {
public:
	virtual ~DisplayCommand() = default;
	DisplayCommand(AbstractFileSystem*);
	virtual int execute(string);
	virtual void displayInfo();
private:
	AbstractFileSystem* fileSystem;
	AbstractFileFactory* fileFactory;
};