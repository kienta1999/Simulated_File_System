#include "LSCommand.h"

LSCommand::LSCommand(AbstractFileSystem* afs) : fileSystem(afs) {
}

void LSCommand::displayInfo() {
	cout << "ls output to the terminal the names of all files currently in the file system \nls can be invoked with the command : ls or ls -m" << endl;
}

int LSCommand::execute(string params) {
	set<string> names = fileSystem->getFileNames();
	if (params == "") {
		int count = 0;
		for (auto itr = names.begin(); itr != names.end(); itr++) {
			cout << *itr << string(LSCommand::MAX_NAME_SIZE - itr->length(), ' ');
			if (count % 2 == 1) {
				cout << endl;
			}
			count++;
		}
		if (count % 2 == 1) cout << endl;
		return static_cast<int>(status::success);
	}
	else if (params == "-m") {
		/*
		MAY BE WRONG
		*/
		for (auto itr = names.begin(); itr != names.end(); itr++) {
			AbstractFile* file = fileSystem->openFile(*itr);
			cout << *itr << string(LSCommand::MAX_NAME_SIZE - itr->length(), ' ');
			cout << file -> getType() << "\t\t";
			cout << file -> getSize() << endl;
			fileSystem->closeFile(file);
		}
		return static_cast<int>(status::success);
	}
	else {
		return static_cast<int>(status::lsFailed);
	}
}
