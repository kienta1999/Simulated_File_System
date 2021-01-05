#include "DisplayCommand.h"

DisplayCommand::DisplayCommand(AbstractFileSystem* afs) : fileSystem(afs) {
}

int DisplayCommand::execute(string filename) {
	bool format = true;
	if (filename.substr(filename.size() - 3) == " -d") {
		//unformated
		filename = filename.substr(0, filename.size() - 3);
		format = false;
	}
	if (!fileSystem->getFileNames().count(filename)) {
		//file not in the system
		return static_cast<int>(status::invalidInput);
	}
	AbstractFile* file = fileSystem->openFile(filename);
	vector<char> content = file->read();
	if (format || file->getType() == "text") {
		//print format
		AbstractFileVisitor* afv = new BasicDisplayVisitor();
		file->accept(afv);
	}
	else {
		//print 1 line
		vector<char> contents = file->read();
		for (int i = 0; i < contents.size(); i++) {
			cout << contents[i];
		}
	}
	cout << endl;
	fileSystem->closeFile(file);
	return static_cast<int>(status::success);
}
void DisplayCommand::displayInfo() {
	cout << "ds opens a file and displays its contents (formatted or not) \n" 
		<< "ds can be invoked with the command : ds or ds -d" << endl;
}
