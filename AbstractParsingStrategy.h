#pragma once
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class AbstractParsingStrategy {
public:
	virtual vector<string> parse(string) = 0;
};