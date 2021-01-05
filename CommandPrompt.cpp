#include "CommandPrompt.h"

CommandPrompt::CommandPrompt() : fileSystem(nullptr), fileFactory(nullptr) {
}

void CommandPrompt::setFileSystem(AbstractFileSystem* afs) {
	fileSystem = afs;
}

void CommandPrompt::setFileFactory(AbstractFileFactory* aff) {
	fileFactory = aff;
}

int CommandPrompt::addCommand(string s, AbstractCommand* ac) {
	if (commandObjects.find(s) != commandObjects.end()) {
		return static_cast<int>(status::duplicatedCommand);
	}
	commandObjects.insert({ s, ac });
	return static_cast<int>(status::success);
}

void CommandPrompt::listCommands() {
	for (auto itr = commandObjects.begin(); itr != commandObjects.end(); itr++) {
		cout << itr->first << endl;
	}
}

string CommandPrompt::prompt() {
	cout << "Enter a command, q to quit, help for a list of commands, \n or help followed by a command name for more information about that command." << endl;
	cout << "$ ";
	string userInput;
	getline(cin, userInput);
	return userInput;
}

int CommandPrompt::run() {
		while (true) {
			string userInput = prompt();
			if (userInput == "q") {
				return 1;
			}
			else if (userInput == "help") {
				listCommands();
			}
			else if (userInput.find(' ') >= userInput.size()) {
				//the input is only 1 word long
				auto itr = commandObjects.find(userInput);
				if (itr != commandObjects.end()) {
					if (itr->second->execute("") != static_cast<int>(status::success)) {
						cout << "Command failed" << endl;
					}
				}
				else {
					cout << "Command " << userInput << " not exist" << endl;
				}
			}
			else {
				//the input is more than 1 word
				istringstream inputStream(userInput);
				string firstWord;
				inputStream >> firstWord;
				if (firstWord == "help") {
					string command;
					inputStream >> command;
					auto itr = commandObjects.find(command);
					if (itr != commandObjects.end()) {
						itr->second->displayInfo();
					}
					else {
						cout << "Command " << command << " not exist" << endl;
					}
				}
				else {
					//the first word is a command name
					auto itr = commandObjects.find(firstWord);
					if (itr != commandObjects.end()) {
						//cout << "str: " << inputStream.str() << endl;
						if (itr->second->execute(inputStream.str().substr(firstWord.length() + 1)) != static_cast<int>(status::success)) {
							cout << "Command " << firstWord << " failed" << endl;
						}
					}
					else {
						cout << "Command " << firstWord << " not exist" << endl;
					}
				}
			}
	}
}

