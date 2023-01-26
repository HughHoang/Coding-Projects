#include <iostream>
#include <fstream>
#include <string>
#include <vector>   
#include <iomanip>
#include "ArgumentManager.h"
#include <stack>
using namespace std;
qinput.
vec.push_back(line);
i++;
struct pos
{
    int row;
    int col;
};
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

    string x,m,n;
    string line = "";
    string sinput;
    getline(inputFile, line);
    x = line[0];
    m = line[2];
    n = line[4];
    int find = stoi(x);
    int row = stoi(m);
    int col = stoi(n);

    vector<vector<int> > vec(col, vector<int>(row));
    vector<pos> findvec;
    pos vecpos;
    int k=0;

    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            inputFile >> vec[i][j];
            if (vec[i][j] == find) {
                vecpos.row = i;
                vecpos.col = j;
                findvec.push_back(vecpos); 
            }
        }
    }
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            for (int findk = 0; findk < findvec.size(); findk++) {
                if (findvec[findk].row == i) {
                    vec[i][j] = find;
                }
                else if (findvec[findk].col == j) {
                   vec[i][j] = find;
                }
            }
        }
    }
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++) {
            outputFile << vec[i][j]<<" ";
        }
        outputFile << endl;
    }
}

