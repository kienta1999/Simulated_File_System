// definitions of basic display visitor here
#include "BasicDisplayVisitor.h"

void BasicDisplayVisitor::visit_TextFile(TextFile* txt) {
	for (int i = 0; i < txt->read().size(); i++) {
		cout << txt->read()[i];
	}
}

void BasicDisplayVisitor::visit_ImageFile(ImageFile* img) {
	int size_ = (int)sqrt(img->getSize());
	for (int ver = 0; ver < size_; ver++) {
		for (int hor = 0; hor < size_; hor++) {
			int index = ver * size_ + hor;
			cout << img->read()[index];
		}
		cout << endl;
	}
}