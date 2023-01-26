/*
    GROUP WORK PERCENTAGES:
    Shaz Ali Momin: 33%
    Scott Tran: 33%
    Hugh Hoang: 33%
*/

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>

#include "ArgumentManager.h"
#include "BinaryTree.h"

using namespace std;

int getDecimalVal(int binary) {
    int binaryNum = binary;
    int value = 0;
    int base = 1;
    int temp = binaryNum;
    
    while (temp) {
        int digit = temp % 10;
        temp = temp / 10;
        value += digit * base;
        base = base * 2;
    }
 
    return value;
}

int getBinaryVal(int decimal) {
    string binaryStr = "";
    int i = 0;

    while(decimal > 0) {
        binaryStr = to_string(decimal % 2) + binaryStr;
        decimal /= 2;
        i++;
    }

    int binary;
    istringstream(binaryStr) >> binary;

    return binary;
}

int getNewPosition(int h1[], int h2[], int size, int oldVal) {
    int temp;
    int index;
    
    for(int i = 0; i < size; i++) {
        if(h1[i] == oldVal) {
            temp = h1[i];
            h1[i] = h2[i];
            h2[i] = temp;

            index = getDecimalVal(h1[i]);

            break;
        }
    }

    return index;
}

// Checks to see if the inventory log is valid or vice versa
bool checkValid(int table[], int h1[], int h2[], int hSize, int tableSize) {
    int count = 0;

    for(int i = 0; i < hSize; i++) {
        bool openSlot = false;
        int index = getDecimalVal(h1[i]);

        if(table[index] == -1) {
            table[index] = h1[i];
        }
        else if(table[index] != -1) {
            int tempVal = table[index];
            table[index] = h1[i];

            // Loop until an open slot in table is found
            // return invalid if infinte loop
            while(!openSlot) {
                int newIndex = getNewPosition(h1, h2, hSize, tempVal);

                if(table[newIndex] == -1) {
                    openSlot = true;
                    table[newIndex] = getBinaryVal(newIndex);
                }
                else {
                    tempVal = table[newIndex];
                    table[newIndex] = getBinaryVal(newIndex);
                }

                count++;

                if(count > 10000) {
                    return false;
                }
            }
        }
    }

    return true;
}

// Gets the ASCII value of the given string of characters
int getASCIIValue(string strLetters) {
    int value = 0;

    for (int i = 0; i < strLetters.length(); i++) {
        value += strLetters[i];
    }

    return value;
}

int main(int argc, char *argv[]) {

    //Implementing Argument Manager
    ArgumentManager am(argc, argv);
    string input = am.get("input");
    string output = am.get("output");
    
    ifstream inFile(input);
    ofstream outFile(output);

    // Temporary file input and output (Change number to test another test case)
    // ifstream inFile("input11.txt");
    // ofstream outFile("output11.txt");

    //Code starts here
    int numTestCase, numTshirt, size;
    int h1_Val, h2_Val;
    bool valid = false;

    int validTableSize;
    int testCasePosStart = 0;
    int testCasePosEnd = 0;
    int validStart = 0;
    int sizeAll = 0;

    inFile >> numTestCase;

    // PART A: VALID OR INVALID INVENTORY CHECK
    for(int i = 0; i < numTestCase; i++) {
        inFile >> numTshirt;
        inFile >> size;

        sizeAll += numTshirt;

        // h1 is the array for the first column of numbers and h2 is the array for the second column
        int h1[numTshirt];
        int h2[numTshirt];

        // table is the array where the binary codes will be added/moved
        int table[size];

        // Setting the values of h1 and h2
        for(int j = 0; j < numTshirt; j++) {
            inFile >> h1_Val;
            inFile >> h2_Val;

            h1[j] = h1_Val;
            h2[j] = h2_Val;
        }

        // Setting all inital values of table to 0
        for(int j = 0; j < size; j++) {
            table[j] = -1;
        }

        valid = checkValid(table, h1, h2, numTshirt, size);

        if(valid == false) {
            outFile << "INVALID INVENTORY LOG!!!" << endl;
            testCasePosStart += numTshirt;
        }
        else {
            outFile << "valid inventory log" << endl;
            validTableSize = size;
            
            if(testCasePosStart == 0) {
                validStart = 0;
            }
            else {
                validStart = testCasePosStart;
            }
            testCasePosEnd = validStart + numTshirt;
        }
    }

    //PART B: PUT ASCII VALUE INTO BINARY TREE AND FIND DISTANCE OF GIVEN VALUE FROM THE ROOT
    BinaryTree tree;
    Tree* root;
    string searchStr;
    vector<string> strArray(sizeAll);
    int distance = 0;

    // The first string of letters that will be used to search the binary tree
    inFile >> searchStr;

    // Adding each string into an array
    for(int i = 0; i < sizeAll; i++) {
        inFile >> strArray[i];
    }

    // Getting the ASCII value of n strings(depending on the size of the valid inventory) and adding to a binary tree

    for(int i = validStart; i < testCasePosEnd; i++) {
        int asciiNum = getASCIIValue(strArray[i]);
        root = tree.addNode(tree.returnRoot(),strArray[i], asciiNum);
        tree.setRoot(root);
    }
    inFile.close();
    tree.printLevelOrder(tree.returnRoot());

    // Finding the distance of the search string from the root node
    distance = tree.findDistanceOfNode(searchStr);

    outFile << distance << endl;

    return 0;
}