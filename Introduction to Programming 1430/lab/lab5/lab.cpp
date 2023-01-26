#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include "ArgumentManager.h"
using namespace std;
typedef map<string, int> Map;
void countWords(ifstream& inputFile, Map& words) {
	string line;
	while (inputFile >> line) {
		++words[line];
	}
}
int main(int argc, char* argv[])
{
	ArgumentManager am(argc, argv);
	const string input = am.get("input");
	const string output = am.get("output");
	const string command = am.get("command");

	ifstream inputFile;
	ofstream outputFile;
	inputFile.open(input);
	outputFile.open(output);
	Map words;
	int size;
	inputFile >> size;
	countWords(inputFile, words);
	for (Map::iterator i = words.begin();
		i != words.end(); ++i) {
		outputFile << i->first << ": " << i->second << endl;
	}
}