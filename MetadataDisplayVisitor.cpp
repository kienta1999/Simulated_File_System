// definitions of metadata visitor here]
#include "MetadataDisplayVisitor.h"

void MetadataDisplayVisitor::visit_TextFile(TextFile* txt) {
	for (int i = 0; i < txt->read().size(); i++) {
		cout << txt->read()[i];
	}
}

void MetadataDisplayVisitor::visit_ImageFile(ImageFile* img) {
	int size_ = img->getSize();
	for (int ver = 0; ver < size_; ver++) {
		for (int hor = 0; hor < size_; hor++) {
			int index = hor * img->getSize() + ver;
			cout << img->read()[index];
		}
		cout << endl;
	}
}