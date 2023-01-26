#include <iostream>
#include <fstream>
#include <string>
#include <queue>  
#include <iomanip>
#include<string.h>
#include <vector>
#include <stdlib.h>
#include <stack>
#include "ArgumentManager.h"
using namespace std;

#include<stdio.h>
#include <stdlib.h>


class node
{
    int height; //height of tree
    int numKeys; //number of keys
    int maxDegree; //Maximum degree
    int* data; //array of numbers
    node** Child; //array of pointers

public:
    node(int inmax);
    void printGivenLevel(struct node* ptr, int level, ofstream& output);
    int insertPos(node* ptr, int data, int n);
    int maxDepth(int height1);
    int getDepth();
    friend class BTree;
};
class BTree
{
    node* root;
    int maxDegree;
public:
    BTree(int inmaxDegree)
    {
        root = NULL;  maxDegree = inmaxDegree;
    }
    int maxDepth()
    {
        if (root != NULL) {
            int height = root->maxDepth(0);
            root->height=height;
            return height;
        }
        else {
            return 0;
        }
    }
    void insert(int num, int inmaxDegree);
    bool updateData(struct node* ptr, int* tempdata, struct node** temp, int inminDegree, int data);
    void printGivenLevel(int level, ofstream& output) {
        if (root != NULL) root->printGivenLevel(root, level, output);
    }
    int searchPos(node* ptr, int data, int n) {
        return root->insertPos(ptr, data, n);
    }

};
int node::getDepth() {
    return height;
}
int node::maxDepth(int height1)
{
    if (this != nullptr)
        return Child[0]->maxDepth(++height1);

    else {
        return height1;
    }
}

node::node(int inmaxDegree)
{
    maxDegree = inmaxDegree;
    data = new int[inmaxDegree - 1];
    Child = new node * [inmaxDegree];
    numKeys = 0;
    height = 0;
}

void BTree::insert(int num, int inmaxDegree)
{
    node* temp = new node(inmaxDegree);
    int tempKey;
    bool split;
    split = updateData(root, &tempKey, &temp, inmaxDegree,num);
    if (split == true)
    {
        struct node* temproot = root;
        root = new node(inmaxDegree);
        root->maxDegree = inmaxDegree;
        root->numKeys = 1;
        root->data[0] = tempKey;
        root->Child[0] = temproot;
        root->Child[1] = temp;
    }
}

bool BTree::updateData(struct node* ptr, int* tempdata, struct node** temp,int inminDegree,int data)
{
    node* curr = new node(inminDegree);
    node* prev = new node(inminDegree);
    bool split;
    int numkeys, median, pos, i, currdata, prevdata;

    if (ptr == NULL)
    {
        *temp = NULL;
        *tempdata = data;
        return true;
    }

    numkeys = ptr->numKeys;
    pos = searchPos(ptr, data, numkeys);

    if ((pos < numkeys) && (data == ptr->data[pos]))
        return false;

    split = updateData(ptr->Child[pos], &currdata, &curr, inminDegree, data);

    if (split != true)
        return split;

    if (numkeys < ptr->maxDegree - 1)
    {

        pos = searchPos(ptr, currdata, numkeys);
        for (i = numkeys; i > pos; i--)
        {
            ptr->data[i] = ptr->data[i - 1];
            ptr->Child[i + 1] = ptr->Child[i];
        }
        ptr->data[pos] = currdata;
        ptr->Child[pos + 1] = curr;
        ++ptr->numKeys;
        return false;

    }
    if (pos == ptr->maxDegree - 1)
    {
        prevdata = currdata;
        prev = curr;
    }
    else
    {
        prevdata = ptr->data[ptr->maxDegree - 2];
        prev = ptr->Child[ptr->maxDegree - 1];
        for (i = ptr->maxDegree - 2; i > pos; i--)
        {
            ptr->data[i] = ptr->data[i - 1];
            ptr->Child[i + 1] = ptr->Child[i];
        }
        ptr->data[pos] = currdata;
        ptr->Child[pos + 1] = curr;
    }
    median = (ptr->maxDegree - 1) / 2;
    (*tempdata) = ptr->data[median];
    node(*node1) = new node(inminDegree);
    *temp = node1;

    ptr->numKeys = median; 
    (*temp)->numKeys = ptr->maxDegree - median - 1;

    for (i = 0; i < (*temp)->numKeys; i++)
    {
        (*temp)->Child[i] = ptr->Child[median + 1 + i];

        if (i < (*temp)->numKeys - 1)
            (*temp)->data[i] = ptr->data[median+1 + i];

        else
            (*temp)->data[i] = currdata;
    }

    (*temp)->Child[(*temp)->numKeys] = prev;
    return true;
}

void node::printGivenLevel(struct node* ptr, int level, ofstream& output)
{
    int i;
    for (i = 0; i < ptr->numKeys; i++)
    {
        if (level == 1)
            output << ptr->data[i] << " ";

        else if (level > 1)
        {
            printGivenLevel(ptr->Child[i], level - 1, output);
        }
    }
    if (level > 1)
    {
        printGivenLevel(ptr->Child[i], level - 1, output);
    }
}

int node::insertPos(node* ptr, int key,  int numkeys)
{
    int pos = 0;
    while (pos < numkeys && key > ptr->data[pos])
        pos++;
    return pos;
}




void deleteword(string& mainStr, const string& toErase)
{
    size_t pos = string::npos;
    while ((pos = mainStr.find(toErase)) != string::npos)
    {
        mainStr.erase(pos, toErase.length());
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
    int num;
    int count = 0;
    ifstream commandFile;
    commandFile.open(command);
    string commandline;
    string sdegree, traversal, slevel;
    int degree, level;
    commandFile >> commandline;
    deleteword(commandline, "Degree=");
    degree = stoi(commandline);
    vector<int> vec;
    int i = 0;
    BTree t(degree);
    while (!inputFile.eof()) {
        bool valid = true;
        inputFile >> num;
        for (int i = 0; i < vec.size(); i++)
        {
            if (vec[i] == num)
            {
                valid = false;
            }
        }
        if (valid)
        {
            t.insert(num, degree);
            vec.push_back(num);
        }
    }
    int height = t.maxDepth();
    outputFile << "Height=" << height << endl;
    while (!commandFile.eof()) {
        getline(commandFile, commandline);
        if (commandline.find(" Traversal") != std::string::npos) {
            if (commandline == "Inorder Traversal") {

            }
            else if (commandline == "Postorder Traversal") {

            }
            else if (commandline == "Preorder Traversal") {

            }
        }
        else if (commandline.find("Level ") != std::string::npos) {
            deleteword(commandline, "Level ");
            level = stoi(commandline);
            if (height>=level) {
                t.printGivenLevel(level, outputFile);
                outputFile << endl;
            }
            else {
                outputFile << "Empty"<<endl;
            }
        }

    }
    commandFile.close();
    inputFile.close();
    outputFile.close();
}





