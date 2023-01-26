#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include "ArgumentManager.h"
using namespace std;
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
	int m, n, x, y;
	inputFile >> m >> n >> x >> y;
	for (int i = 0; i < n; i++) {

	}
}