#include "provided.h"
#include <iostream>
#include <string>
#include <vector>
#include <cassert>
using namespace std;

int main() {
	Tokenizer t(" ,.!");
	vector<string> v = t.tokenize("This,, is a test! It's the... best!");
	assert(v.size() == 7);
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << endl;
	// v now contains "This","is","a","test","It's","the", and "best"
	string s = "!!!!";
	v = t.tokenize(s);
	assert(v.size() == 0);
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << endl;
	// v is now empty
}