#include "CopyCommand.h"

CopyCommand::CopyCommand(AbstractFileSystem* afs) : fileSystem(afs){

}

int CopyCommand::execute(string filename) {
	int index = filename.find(' ');
	if (index == string::npos) {
		//no space found
		return static_cast<int>(status::cpFailed);
	}
	string originalName = filename.substr(0, index);
	string newName = filename.substr(index + 1);

	if (!fileSystem->getFileNames().count(originalName)) {
		//file not in the system
		return static_cast<int>(status::cpFailed);
	}
	AbstractFile* file = fileSystem->openFile(originalName);
	AbstractFile* newFile = file->clone(newName);
	fileSystem->closeFile(file);

	if (newFile->getName() == originalName || fileSystem->getFileNames().count(newFile->getName()) ) {
		//if the original file has same name as new file 
		//or system already has a file with newName
		delete newFile;
		return static_cast<int>(status::invalidInput);
	}
	fileSystem->addFile(newFile->getName(), newFile);
	return static_cast<int>(status::success);
}

void CopyCommand::displayInfo() {
	cout << "cp copies a file that exists in the file system and add the copy to the file system with a different name \n"
		<< "cp can be invoked with the command : cp <file_to_copy> <new_name_with_no_extension>" << endl;
}