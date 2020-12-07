#include "TextFile.h"

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

void TextFile::accept(AbstractFileVisitor* afv) {
	if (afv) {
		afv->visit_TextFile(this);
	}
}