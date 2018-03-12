#include "provided.h"
#include <iostream>
#include <string>
#include <cassert>
using namespace std;

int main() {
	Translator t; 
	string secret = "Hdqlx!";
	string translated = t.getTranslation(secret);
	assert(translated == "?????!");

	t.pushMapping("DHL", "ERD");
	translated = t.getTranslation(secret);
	assert(translated == "Re?d?!");

	t.pushMapping("QX", "AY");
	translated = t.getTranslation(secret);
	assert(translated == "Ready!");

	t.popMapping();
	translated = t.getTranslation(secret);
	assert(translated == "Re?d?!");

	t.popMapping();
	translated = t.getTranslation(secret);
	assert(translated == "?????!");

	t.pushMapping("DHL", "ERD");
	assert(!t.pushMapping("QX", "RY"));
	translated = t.getTranslation("HDX");
	assert(translated == "RE?");
	assert(!t.pushMapping("H", "S"));

	cout << "Passed all tests." << endl;
}