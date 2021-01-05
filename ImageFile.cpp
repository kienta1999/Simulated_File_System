// definition of ImageFile class here
#include "ImageFile.h"
#include "AbstractFileVisitor.h"

ImageFile::ImageFile(string fileName) : name(fileName), size('0') {

}

unsigned int ImageFile::getSize() {
	return contents.size();
}

string ImageFile::getName() {
	return name;
}

int ImageFile::write(vector<char> charVect) {
	contents.clear();
	int size_ = charVect[charVect.size() - 1] - '0';
	if (size_ > 9 || size_ < 0 || charVect.size() - 1 != size_*size_) {
		contents.clear();
		size = '0';
		return static_cast<int>(status::invalidInput);
	}
	for (int i = 0; i < charVect.size() - 1; i++) {
		if (charVect[i] != 'X' && charVect[i] != ' ') {
			contents.clear();
			size = '0';
			return static_cast<int>(status::invalidInput);
		}
		else {
			contents.push_back(charVect[i]);
		}
	}
	size = charVect[charVect.size() - 1];
	
	return static_cast<int>(status::success);
}

int ImageFile::append(vector<char>) {
	cout << "An image file should not support append" << endl;
	return static_cast<int>(status::noAppend);
}

vector<char> ImageFile::read() {
	/*int size_ = size - '0';
	for (int ver = 0; ver < size_; ver++) {
		for (int hor = 0; hor < size_; hor++) {
			int index = getIndex(hor, ver);
			cout << contents[index];
		}
		cout << endl;
	}*/
	return contents;
}

int ImageFile::getIndex(int x, int y) {
	return y * (size - '0') + x;
}

void ImageFile::accept(AbstractFileVisitor* afv) {
	if (afv) {
		afv->visit_ImageFile(this);
	}
}

string ImageFile::getType() {
	return "image";
}

AbstractFile* ImageFile::clone(string newName) {
	AbstractFile* file = new ImageFile(newName + ".img");
	file->write(this->read());
	return file;
}