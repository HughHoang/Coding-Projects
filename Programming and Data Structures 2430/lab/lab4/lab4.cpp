#include <iostream>
#include <fstream>
#include <string>
#include <vector>   
#include <iomanip>
#include "ArgumentManager.h"
using namespace std;

struct Node
{
    string str;
    float time;
    Node* tail;
    Node* next;
    Node* prev;
};
Node* top = NULL;

void add(Node* head, string instr, float intime)
{
    Node* temp = new Node;
    temp->str = instr;
    temp->time = intime;
    temp->prev = NULL;
    temp->next = NULL;
    if (top == NULL)
    {
        top = temp;
    }

    else
    {
        Node* ptr = new Node;
        ptr = top;

        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }

        temp->prev = ptr;
        ptr->next = temp;
    }
}
void sort(Node* head)
{

    if (head == NULL) {
        return;
    }
    else {
        Node* temphead = head;
        float tempid;
        string tempname, tempdifficulty;

        int counter = 0;
        while (temphead)
        {
            temphead = temphead->next;
            counter++;
        }
        temphead = head;

        for (int j = 0; j < counter; j++)
        {
            while (temphead->next)
            {
                if (temphead->time > temphead->next->time)
                {
                    tempid = temphead->time;
                    temphead->time = temphead->next->time;
                    temphead->next->time = tempid;

                    tempname = temphead->str;
                    temphead->str = temphead->next->str;
                    temphead->next->str = tempname;
                }
                temphead = temphead->next;
            }
            temphead = head;
        }
    
    }
}
float getNumberFromString(string s) {
    stringstream str_strm;
    str_strm << s; 
    string temp_str;
    float temp_int;
    while (!str_strm.eof()) {
        str_strm >> temp_str; 
        if (stringstream(temp_str) >> temp_int) { 
            return temp_int;
        }
        temp_str = ""; 
    }
    return temp_int;
}
string stringNoNumber(string s) {
    string out;
    for (int i = 0; i < s.length(); i++) {
        if ((isdigit(s[i])==false)&&(s[i] != '.')) {
            out += s[i];
        }
    }
    return out;
}
void printList(ofstream& output, Node* top) {
    while (top != NULL) {
        output << top->str <<endl;
        top = top->next;
    }
}
int main(int argc, char* argv[])
{
    ArgumentManager am(argc, argv);
    const string input = am.get("input");
    const string output = am.get("output");


    ifstream inputFile;
    ofstream outputFile;
    inputFile.open(input);
    outputFile.open(output);
    string line;
    string instr;
    float intime;
    while (!inputFile.eof()) {
        getline(inputFile, line);
        while (line.length() == 0) {
            getline(inputFile, line);
        }
        intime =getNumberFromString(line);
        instr =stringNoNumber(line);
        add(top, instr, intime);
        sort(top);
    }
    printList(outputFile, top);
    outputFile.close();
    inputFile.close();
            
}

