#include "TouchCommand.h"

TouchCommand::TouchCommand(AbstractFileSystem* afs, AbstractFileFactory* aff): fileSystem(afs), fileFactory(aff){
}

void TouchCommand::displayInfo() {
	cout << "touch creates a file, touch can be invoked with the command : touch < filename>" << endl;
}

int TouchCommand::execute(string filename) {
	if (filename.substr(filename.size() - 3) == " -p") {
		//with password
		string filenamePsw = filename.substr(0, filename.size() - 3);
		AbstractFile* protectedFile = fileFactory->createFile(filenamePsw);
		if (protectedFile == nullptr) {
			return static_cast<int>(status::createFailed);
		}
		else {
			string password;
			cout << "What is the password?" << endl;
			cin >> password;
			AbstractFile* proxy = new PasswordProxy(protectedFile, password);
			int statusAdd = fileSystem->addFile(filenamePsw, proxy);
			if (statusAdd != static_cast<int>(status::success)) {
				delete proxy;
			}
			return statusAdd;
		}
	}
	else {
		//no password
		AbstractFile* file = fileFactory->createFile(filename);
		if (file == nullptr) {
			return static_cast<int>(status::createFailed);
		}
		int statusAdd = fileSystem->addFile(filename, file);
		if (statusAdd != static_cast<int>(status::success)) {
			delete file;
		}
		return statusAdd;
	}
}
