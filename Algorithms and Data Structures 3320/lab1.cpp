#include <iostream>
#include <fstream>
#include <string>
#include <vector>   
#include <iomanip>
#include "ArgumentManager.h"
using namespace std;

int main(int argc, char* argv[])
{
    ArgumentManager am(argc, argv);
    const string input = am.get("input");
    const string output = am.get("output");

    ifstream inputFile;
    ofstream outputFile;
    inputFile.open(input);
    outputFile.open(output);
    int signnum=0;
    string line = "";;
    char char1 = '\0';
    char char2 = '\0';
    try
    {
        if (inputFile) {
            if (outputFile) {
                while (!inputFile.eof()) {
                    inputFile >> signnum;
                    inputFile >> char1 >> char2;
                }
                inputFile.close();
            }
            else {
                string out = "File not found";
                throw(out);
            }
        }
        else {
            string out = "File not found";
            throw(out);
        }
        int z = 0;
        if (signnum == 1) {
            z = char1 + char2;
            outputFile << z;
        }
        else {
            z = char1 - char2;
            if (z < 0) {
                string out= "negative result";
                throw(out);
            }
            else {
                outputFile << z;
            }
        }
        outputFile.close();
    }
    catch (string err)
    {
        outputFile << "ERROR: " << err;
    }
}

