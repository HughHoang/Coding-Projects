#include <iostream>
#include <fstream>
#include <string>
#include <vector>   
#include <iomanip>
#include "ArgumentManager.h"
using namespace std;


class Problem {
private:
    struct node
    {
        string line;

        node* next;
        node* prev;
    };
    node* head, * tail;
    int size = 0;
public:
    Problem() {
        head = nullptr;
        tail = nullptr;
        int size = 0;
    }
    void add(string strline);
    void display(ofstream& output);
    void reverse();
};

void Problem::add(string strline)
{
    node* tmp = new node;
    tmp->line = strline;
    tmp->next = NULL;
    if (head == nullptr)
    {
        head = tmp;
        tail = tmp;
    }
    else
    {
        tail->next = tmp;
        tail = tail->next;
    }
    size++;
}
void Problem::display(ofstream& output)
{
    struct node* temp = head;
    if (size == 0) {
        return;
    }
    if (size == 1) {
        output << temp->line << " ";
    }
    else
    {
        while (temp != NULL) {
            output << temp->line << " ";
            temp = temp->next;
        }
    }
}
void Problem::reverse()
{
    node* current = head;
    node* prev = NULL, * next = NULL;

    while (current != NULL) {
        next = current->next;

        current->next = prev;

        prev = current;
        current = next;
    }
    head = prev;
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
    Problem Llist;
    string blank;
    string line;
    while (!inputFile.eof()) {
        Llist.add(line);
        inputFile >> line;
    }
    Llist.reverse();
    Llist.display(outputFile);
    outputFile.close();
    inputFile.close();
            
}

