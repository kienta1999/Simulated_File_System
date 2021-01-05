#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"
#include "BasicDisplayVisitor.h"
#include "MetadataDisplayVisitor.h"

class CopyCommand : public AbstractCommand {
public:
	virtual ~CopyCommand() = default;
	CopyCommand(AbstractFileSystem*);
	virtual int execute(string);
	virtual void displayInfo();
private:
	AbstractFileSystem* fileSystem;
	AbstractFileFactory* fileFactory;
};