// definitions of metadata visitor here]
#include "MetadataDisplayVisitor.h"

void MetadataDisplayVisitor::visit_TextFile(TextFile* txt) {
	cout << txt->getName() << endl;
	cout << txt->getSize() << endl;
	cout << "text" << endl;
}

void MetadataDisplayVisitor::visit_ImageFile(ImageFile* img) {
	cout << img->getName() << endl;
	cout << img->getSize() << endl;
	cout << "image" << endl;
}