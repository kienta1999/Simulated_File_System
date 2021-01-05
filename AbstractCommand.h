#pragma once

#include <vector>
#include <string>
#include <iostream>
using namespace std;

class AbstractCommand {
public:
	virtual int execute(string) = 0;
	virtual void displayInfo() = 0;
	virtual ~AbstractCommand() = default;
};