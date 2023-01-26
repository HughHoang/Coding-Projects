#include<iostream>
#include <iomanip> 
#include <string>
#include <fstream>
#include <sstream>
#include "antique.h"
#include "merchant.h"
using namespace std;

int main()
{
    int stockArr[10];
    Antique antArr[10];
    int inStock;
    string inName;
    float budget;
    int playerOption;
    string filename;
    string line;
    int inPrice;
    string getName, getPrice;
    int count = 0;
    cin >> inStock;
    cin >> filename;
    ifstream inFile(filename);
    if (!inFile.is_open()) {
        cout << "Error! File not found." << endl;
        
    }
    if (inFile.is_open()) {
        while (getline(inFile,line)) {
            stringstream ss(line);

            mutators(inName, inPrice);
            count++;
        }
    }
    inFile.close();
    cout << "Enter in budget : $";
    cin >> budget;
    cout << "Make a selection : ";
    cout << "1 - Haggle";
    cout << "2 - View menu";
    cout << "3 - Select an antique";
    cout << "4 - Leave";
    cin >> playerOption;
    if (playerOption == 1) {

    }
}

