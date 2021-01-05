#include "MacroCommand.h"

MacroCommand::MacroCommand(AbstractFileSystem* afs) : fileSystem(afs) {}

int MacroCommand::execute(string filename) {
	vector<string> inputString = parsingStrategy->parse(filename);
	for (int i = 0; i < allCommands.size(); i++) {
		int status = allCommands[i]->execute(inputString[i]);
		if (status != static_cast<int>(status::success)) {
			return status;
		}
	}
	return static_cast<int>(status::success);
}

void MacroCommand::displayInfo() {
	cout << "This is a macro command" << endl;
}

void MacroCommand::addCommand(AbstractCommand* cmd) {
	allCommands.push_back(cmd);
}

void MacroCommand::setParseStrategy(AbstractParsingStrategy* aps) {
	parsingStrategy = aps;
}