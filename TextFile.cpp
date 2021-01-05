#include "TextFile.h"
#include "AbstractFileVisitor.h"

//  Define the TextFile class here
TextFile::TextFile(string fileName): name(fileName) {

}

unsigned int TextFile::getSize() {
	return contents.size();
}

string TextFile::getName() {
	return name;
}

int TextFile::write(vector<char> charVect) {
	contents = charVect;
	return static_cast<int>(status::success);
}

int TextFile::append(vector<char> charVect) {
	for (int i = 0; i < charVect.size(); i++) {
		contents.push_back(charVect[i]);
	}
	return static_cast<int>(status::success);
}

vector<char> TextFile::read() {
	/*for (int i = 0; i < contents.size(); i++) {
		cout << contents[i];
	}*/
	return contents;
}

//need to know AbstractFileVisitor's functionality
void TextFile::accept(AbstractFileVisitor* afv) {
	if (afv) {
		afv->visit_TextFile(this);
	}
}

string TextFile::getType() {
	return "text";
}

AbstractFile* TextFile::clone(string newName) {
	AbstractFile* file = new TextFile(newName + ".txt");
	file->write(this->read());
	return file;
}