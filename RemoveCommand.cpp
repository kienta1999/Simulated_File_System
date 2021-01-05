#include "RemoveCommand.h"

RemoveCommand::RemoveCommand(AbstractFileSystem* afs) : fileSystem(afs){
}

void RemoveCommand::displayInfo() {
	cout << "rm removes a file, \nrm can be invoked with the command : rm <filename>" << endl;
}

int RemoveCommand::execute(string filename) {
	return fileSystem->deleteFile(filename);
}