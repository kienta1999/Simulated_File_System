#pragma once
// declaration of the file visitor interface here
#include "AbstractFile.h"
#include "TextFile.h"
#include "ImageFile.h"

class AbstractFileVisitor {
public:
	virtual void visit_TextFile(TextFile*) = 0;
	virtual void visit_ImageFile(ImageFile*) = 0;
};