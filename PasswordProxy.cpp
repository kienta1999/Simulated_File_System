#include "PasswordProxy.h"

PasswordProxy::PasswordProxy(AbstractFile* af, string pw): password(pw), protectedFile(af){
}

PasswordProxy::~PasswordProxy() {
	delete protectedFile;
}
string PasswordProxy::passwordPrompt() {
	string inputPwd;
	cout << "Enter the password" << endl;
	cin >> inputPwd;
	return inputPwd;
}
bool PasswordProxy::passwordCheck(string input) {
	return input == password;
}

unsigned int PasswordProxy::getSize() {
	return protectedFile->getSize();
}

string PasswordProxy::getName() {
	return protectedFile->getName();
}

vector<char> PasswordProxy::read() {
	string input = passwordPrompt();
	if (passwordCheck(input))
		return protectedFile->read();
	else
		return vector<char>();
}

int PasswordProxy::write(vector<char> charVect) {
	string input = passwordPrompt();
	if (passwordCheck(input))
		return protectedFile->write(charVect);
	else
		return static_cast<int>(status::wrongPassword);
}

int PasswordProxy::append(vector<char> charVect) {
	string input = passwordPrompt();
	if (passwordCheck(input))
		return protectedFile->append(charVect);
	else
		return static_cast<int>(status::wrongPassword);
}

//need to know AbstractFileVisitor's functionality
void PasswordProxy::accept(AbstractFileVisitor* afv) {
	string input = passwordPrompt();
	if (passwordCheck(input))
		protectedFile->accept(afv);
}

string PasswordProxy::getType() {
	return protectedFile->getType();
}

AbstractFile* PasswordProxy::clone(string newName) {
	AbstractFile* file = protectedFile->clone(newName);
	return new PasswordProxy(file, password);
}