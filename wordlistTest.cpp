#include "provided.h"
#include <iostream>
#include <string>
#include <vector>
#include <cassert>
using namespace std;

int main() {
	WordList wl;
	if (!wl.loadWordList("wordlist.txt"))
	{
		cout << "Unable to load word list" << endl;
		return 0;
	}
	assert(wl.contains("onomatopoeia"));
	assert(wl.contains("'em"));

	string cipher = "xyqbbq";
	string decodedSoFar = "?r????";
	vector<string> v = wl.findCandidates(cipher, decodedSoFar);
	assert(!v.empty());
	for (size_t k = 0; k < v.size(); k++)
		assert(v[k] == "grotto" || v[k] == "troppo");
	cout << "Passed all Test Cases" << endl;
}