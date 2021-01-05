#pragma once
#include "AbstractParsingStrategy.h"
#include "AbstractFile.h"

class RenameParsingStrategy : public AbstractParsingStrategy {
public:
	virtual vector<string> parse(string);
};
