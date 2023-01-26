#include <iostream>
#include <fstream>
#include <string>
#include <vector>   
#include <iomanip>
#include "ArgumentManager.h"
using namespace std;

string Spiral(string** mat, int, int, int, int, int, int, string, string&, int);
void Reverse(string, string, string);

int main(int argc, char* argv[])
{
    ArgumentManager am(argc, argv);
    const string input = am.get("input");
    const string output = am.get("output");

    ifstream inputFile;
    ofstream outputFile;
    string target = "start";
    outputFile.open(output.c_str());
    outputFile.close();
    Reverse(target, input, output);
}

string Spiral(string** _mat, int x, int y, int lrowbound, int lcolbound, int row, int col, string output, string& temp, int count) {

    if (count == ((row + lrowbound) * (col + lcolbound))) {
        return temp;
    }
    else if ((x == lrowbound) && (y != col - 1)) {
        temp += (_mat[x][y]);
        count++;
        return Spiral(_mat, x, y + 1, lrowbound, lcolbound, row, col, output, temp, count);
    }
    else if ((x != row - 1) && (y == col - 1)) {
        temp += (_mat[x][y]);
        count++;
        return Spiral(_mat, x + 1, y, lrowbound, lcolbound, row, col, output, temp, count);
    }

    else if ((x == lrowbound + 1) && (y == lcolbound)) {
        temp += (_mat[x][y]);
        count++;
        row--;
        col--;
        lcolbound++;
        lrowbound++;
        return Spiral(_mat, x, y + 1, lrowbound, lcolbound, row, col, output, temp, count);
    }

    else if ((x != lrowbound) && (y == lcolbound)) {
        temp += (_mat[x][y]);
        count++;
        return Spiral(_mat, x - 1, y, lrowbound, lcolbound, row, col, output, temp, count);
    }
    else if ((x == row - 1) && (y != 0)) {
        temp += (_mat[x][y]);
        count++;
        return Spiral(_mat, x, y - 1, lrowbound, lcolbound, row, col, output, temp, count);
    }
    return temp;
}

void Reverse(string target, string input, string output) {
    if (target == "finish") {
        return;
    }
    ifstream inputFile;
    ofstream outputFile;
    inputFile.open(input.c_str());
    string srow, scol;
    string word = "";
    int lrowbound = 0;
    int lcolbound = 0;
    int count = 0;
    string temp = "";
    while (word != target) {
        inputFile >> word;
    }
    inputFile >> word;
    srow = word[0];
    scol = word[2];
    int row = stoi(srow);
    int col = stoi(scol);

    string** mat = new string * [row];
    for (int i = 0; i < row; i++) {
        mat[i] = new string[col];
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            inputFile >> mat[i][j];
            cout << mat[i][j];
        }
    }

    string outtext = Spiral(mat, 0, 0, lrowbound, lcolbound, row, col, output, temp, count);
    inputFile.close();
    Reverse(outtext, input, output);
    outputFile.open(output.c_str(), ios_base::app);
    outputFile << target << endl;
    outputFile.close();
    for (int i = 0; i < row; ++i) {
        delete[]mat[i];
    }
    delete[]mat;
}





