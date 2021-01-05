#include "RenameParsingStrategy.h"

vector<string> RenameParsingStrategy::parse(string filename) {
	vector<string> ans;
	int index = filename.find(' ');
	if (index == string::npos) {
		//no space found
		return ans;
	}
	string originalName = filename.substr(0, index);
	ans.push_back(filename);
	ans.push_back(originalName);
	return ans;
	// rn exist new = cp exist new + rm exist
}