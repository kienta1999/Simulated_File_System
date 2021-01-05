// Main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "TextFile.h"
#include "ImageFile.h"
#include "SimpleFileFactory.h"
#include "SimpleFileSystem.h"
#include "BasicDisplayVisitor.h"
#include "MetadataDisplayVisitor.h"
#include "PasswordProxy.h"
#include "TouchCommand.h"
#include "CommandPrompt.h"
#include "CommandTest.h"
#include "LSCommand.h"
#include "RemoveCommand.h"
#include "CatCommand.h"
#include "DisplayCommand.h"
#include "CopyCommand.h"
#include "MacroCommand.h"
#include "MacroCommand.h"
#include "RenameParsingStrategy.h"

int main()
{
	AbstractFileSystem* sfs = new SimpleFileSystem();
	AbstractFileFactory* sff = new SimpleFileFactory();
	CommandPrompt* cp = new CommandPrompt;
	cp->setFileSystem(sfs);
	cp->setFileFactory(sff);
	// ADD COMMAND
	LSCommand* ls = new LSCommand(sfs);
	cp->addCommand("ls", ls);
	TouchCommand* tc = new TouchCommand(sfs, sff);
	cp->addCommand("touch", tc);
	RemoveCommand* rm = new RemoveCommand(sfs);
	cp->addCommand("rm", rm);
	CatCommand* cc = new CatCommand(sfs);
	cp->addCommand("cat", cc);
	DisplayCommand* dc = new DisplayCommand(sfs);
	cp->addCommand("ds", dc);
	CopyCommand* copyC = new CopyCommand(sfs);
	cp->addCommand("cp", copyC);

	MacroCommand* rc = new MacroCommand(sfs);
	rc->addCommand(copyC);
	rc->addCommand(rm);
	rc->setParseStrategy(new RenameParsingStrategy());
	cp->addCommand("rn", rc);

	int response = cp->run();
	return 0;
}
