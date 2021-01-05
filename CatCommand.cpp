#include "CatCommand.h"

CatCommand::CatCommand(AbstractFileSystem* afs) : fileSystem(afs){
}

int CatCommand::execute(string filename) {
	bool append = false;
	string action = "write";
	if (filename.substr(filename.size() - 3) == " -a") {
		//append
		filename = filename.substr(0, filename.size() - 3);
		append = true;
		action = "append";
	}
	if (!fileSystem->getFileNames().count(filename)) {
		//file not in the system
		return static_cast<int>(status::invalidInput);
	}
	AbstractFile* file = fileSystem->openFile(filename);
	vector<char> content = file->read();
	if (append) {
		//display byte of the file here - NEED FIX
		for (auto itr = content.begin(); itr != content.end(); itr++) {
			cout << *itr;
		}
		cout << endl;
	}
	vector<char> temp;
	string input;

	while (true) {
		cout << "Enter data you would like to " << action << " to the file." << endl 
			<< "Enter :wq to save the file and exit, enter :q to exit without saving." << endl;
		getline(cin, input);
		if (input == ":q") {
			fileSystem->closeFile(file);
			return static_cast<int>(status::success);
		}
		if (input == ":wq") {
			temp.pop_back();
			int statusWq;
			if (append) {
				statusWq = file->append(temp);
			}
			else {
				statusWq = file->write(temp);
			}
			fileSystem->closeFile(file);
			return statusWq;
		}
		temp.insert(temp.end(), input.begin(), input.end());
		temp.push_back('\n');
	}
	return static_cast<int>(status::success);
}

void CatCommand::displayInfo() {
	cout << "cat concatenate files, cat can be invoked with the command : cat <filename> [-a]" << endl;
	cout << "Add optional -a to append. Omit it to overwrite to the file" << endl;
}