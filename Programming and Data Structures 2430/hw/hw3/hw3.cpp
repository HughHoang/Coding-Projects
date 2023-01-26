#include <iostream>
#include <fstream>
#include <string>
#include <vector>   
#include <iomanip>
#include "ArgumentManager.h"
#include <stack>
using namespace std;

struct Node
{
    string fix;
    string data;
    Node* tail;
    Node* next;
    Node* prev;
};
Node* top = NULL;
Node* nodestack = NULL;

void add(Node* head, string str, string fix1)
{
    Node* temp = new Node;
    temp->data = str;
    temp->fix = fix1;
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
void push(string str, string fix1) {
    Node* newnode = new Node;
    newnode->data = str;
    newnode->fix = fix1;
    newnode->prev = NULL;
    newnode->next = nodestack;

    if ((nodestack) != NULL)
        (nodestack)->prev = newnode;

    nodestack = newnode;
}
bool boolSign(char x) {
    switch (x) {
    case '+':
    case '-':
    case '/':
    case '*':
        return true;
    }
    return false;
}
string postToPre(string post)
{
    stack<string> stck;
    int len = post.size();

    for (int i = 0; i < len; i++) {

        if (boolSign(post[i])) {
            string op1 = stck.top();
            stck.pop();
            string op2 = stck.top();
            stck.pop();
            string temp = post[i] + op2 + op1;
            stck.push(temp);
        }

        else {
            stck.push(string(1, post[i]));
        }
    }

    string out = "";
    while (!stck.empty()) {
        out += stck.top();
        stck.pop();
    }
    return out;
}
string preToPost(string pre) {

    stack<string> stck;
    int len = pre.size();

    for (int i = len - 1; i >= 0; i--) {

        if (boolSign(pre[i])) {

            string op1 = stck.top(); 
            stck.pop();
            string op2 = stck.top(); 
            stck.pop();
            string temp = op1 + op2 + pre[i];
            stck.push(temp);

        }

        else {
            stck.push(string(1, pre[i]));
        }
    }
    return stck.top();
}
string removeSpaces(string str)
{
    string temp = "";
    int i;
    for (i = 0; i < str.length(); i++)
    {
        if (str[i] != ' ')
            temp += str[i];
    }
    str = temp;
    return str;
}
string paren(string str)
{
    string out = "";
    int i;
    bool pos = false;
    for (i = 0; i < str.length(); i++)
    {
        if (str[i] == '(') {
            pos = true;
        }
        else if ((str[i] != ')') && (pos == true)) {
            out += str[i];
        }
    }
    str = out;

    return str;
}
string comm(string str)
{
    string out = "";
    int i;
    bool pos = false;
    for (i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ') {
            str = out;
            return str;
        }
        if (str[i] != '(') {
            out += str[i];
        }
    }
    str = out;
    return str;
}
void convertList(string param, int size, Node* type)
{
    Node* temp;
    temp = type;
    if (param == "postfix") {
        while (temp != nullptr)
        {
            if ((temp->fix) == "postfix") {
                temp->data = postToPre(temp->data);
                temp->fix = "prefix";
            }
            temp = temp->next;
        }
    }
    else if (param == "prefix") {
        while (temp != nullptr)
        {
            if ((temp->fix) == "prefix") {
                temp->data = preToPost(temp->data);
                temp->fix = "postfix";
            }
            temp = temp->next;
        }
    }
    else if (param == "all") {
        while (temp != nullptr)
        {
            if ((temp->fix) == "postfix") {
                temp->data = postToPre(temp->data);
                temp->fix = "prefix";
            }
            else if ((temp->fix) == "prefix") {
                temp->data = preToPost(temp->data);
                temp->fix = "postfix";
            }

            temp = temp->next;
        }
    }
    else {
        int pos1 = stoi(param);
        if (pos1 <= 0) {
            pos1 = 0;
        }
        else if (pos1 > size - 1) {
            return;
        }
        for (int i = 0; i < pos1; i++) {
            temp = temp->next;
        }
        if ((temp->fix) == "postfix") {
            temp->data = postToPre(temp->data);
            temp->fix = "prefix";
        }
        else if ((temp->fix) == "prefix") {
            temp->data = preToPost(temp->data);
            temp->fix = "postfix";
        }
    }
    return;
}
void removeList(string param, Node* type, int size) {
    int count = 0;
    Node* ptr = new Node;
    ptr = top;
    Node* next;

    if (param == "postfix") {
        while (ptr != NULL) {
            next = ptr->next;
            if (ptr->fix == param) {
                if (top == NULL || ptr == NULL)
                    return;
                if (top == ptr)
                    top = ptr->next;

                if (ptr->next != NULL)
                    ptr->next->prev = ptr->prev;

                if (ptr->prev != NULL)
                    ptr->prev->next = ptr->next;
                push(ptr->data, ptr->fix);

                free(ptr);
            }
            ptr = next;
        }
    }
    else if (param == "prefix") {
        while (ptr != NULL) {
            next = ptr->next;
            if (ptr->fix == param) {
                if (top == NULL || ptr == NULL)
                    return;
                if (top == ptr)
                    top = ptr->next;

                if (ptr->next != NULL)
                    ptr->next->prev = ptr->prev;

                if (ptr->prev != NULL)
                    ptr->prev->next = ptr->next;
                push(ptr->data, ptr->fix);

                free(ptr);
            }
            ptr = next;
        }
    }
    else if (param == "all") {
        while (ptr != NULL) {
            next = ptr->next;
            if (top == NULL || ptr == NULL)
                return;
            if (top == ptr)
                top = ptr->next;

            if (ptr->next != NULL)
                ptr->next->prev = ptr->prev;

            if (ptr->prev != NULL)
                ptr->prev->next = ptr->next;
            push(ptr->data, ptr->fix);

            free(ptr);

            ptr = next;
        }
    }
    else {
        int pos1 = stoi(param);
        if (top == NULL)
            return;

        Node* temp = top;
        if (pos1 == 0)
        {
            top = temp->next;
            free(temp);
            return;
        }

        for (int i = 0; temp != NULL && i < pos1 - 1; i++)
            temp = temp->next;

        if (temp == NULL || temp->next == NULL)
            return;

        Node* next = temp->next->next;
        free(temp->next);
        temp->next = next;
    }
}
void printList(ofstream& output, Node* top) {
    while (top != NULL) {
        output << top->fix << ":";
        output << top->data << endl;
        top = top->next;
    }
}
int checkSize(Node* type) {
    int count = 0;
    Node* current = type;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}
void printListBackwards(ofstream& output, Node* top) {
    if (top == NULL) {
        return;
    }

    printListBackwards(output, top->next);

    output << top->fix << ":";
    output << top->data << endl;
    top = top->next;

}
void pushReserve(string param, int size) {
    Node* ptr = top;
    Node* next;
    int count = 0;
    string str;
    if (param == "all") {
        while (ptr != NULL) {
            next = ptr->next;
            if (top == NULL || ptr == NULL)
                return;
            if (top == ptr)
                top = ptr->next;

            if (ptr->next != NULL)
                ptr->next->prev = ptr->prev;

            if (ptr->prev != NULL)
                ptr->prev->next = ptr->next;
            push(ptr->data, ptr->fix);

            free(ptr);

            ptr = next;
        }
    }
    else if (param == "prefix") {
        while (ptr != NULL) {
            next = ptr->next;
            if (ptr->fix == param) {
                if (top == NULL || ptr == NULL)
                    return;
                if (top == ptr)
                    top = ptr->next;

                if (ptr->next != NULL)
                    ptr->next->prev = ptr->prev;

                if (ptr->prev != NULL)
                    ptr->prev->next = ptr->next;
                push(ptr->data, ptr->fix);

                free(ptr);
            }
            ptr = next;
        }
    }
    else if (param == "postfix") {
        while (ptr != NULL) {
            next = ptr->next;
            if (ptr->fix == param) {
                if (top == NULL || ptr == NULL)
                    return;
                if (top == ptr)
                    top = ptr->next;

                if (ptr->next != NULL)
                    ptr->next->prev = ptr->prev;

                if (ptr->prev != NULL)
                    ptr->prev->next = ptr->next;
                push(ptr->data, ptr->fix);

                free(ptr);
            }
            ptr = next;
        }
    }
    else {
        int pos1 = stoi(param);
        for (int i = 0; i < pos1 - 1; i++) {
            next = ptr->next;
            ptr = next;
        }
        while (ptr != NULL) {
            next = ptr->next;
            if (count == pos1) {
                if (top == NULL || ptr == NULL)
                    return;
                if (top == ptr)
                    top = ptr->next;

                if (ptr->next != NULL)
                    ptr->next->prev = ptr->prev;

                if (ptr->prev != NULL)
                    ptr->prev->next = ptr->next;
                push(ptr->data, ptr->fix);

                free(ptr);
                count++;
            }
            ptr = next;
        }
    }
}
void popReserve(int pos) {

    int i;
    Node* temp1 = new Node;
    temp1->data = nodestack->data;
    temp1->fix = nodestack->fix;
    temp1->next = NULL;
    string str = to_string(pos);
    if (checkSize(nodestack) == 0) {
        return;
    }
    if (checkSize(top) == 0) {
        add(top, nodestack->data, nodestack->fix);
        return;
    }
    if (pos <= 0)
    {
        temp1->next = top;
        top = temp1;
        return;
    }
    else if (pos > checkSize(top)) {
        pos = checkSize(top);
    }
    Node* temp2 = top;
    for (i = 0; i < pos - 1; i++)
    {
        temp2 = temp2->next;
    }

    temp1->next = temp2->next;
    temp2->next = temp1;
}
void flipReserve() {
    stack<Node*> stck;
    Node* curr = nodestack;

    while (curr != NULL)
    {
        stck.push(curr);
        curr = curr->next;
    }
    Node* temp = stck.top();
    nodestack = temp;
    stck.pop();
    while (!stck.empty())
    {

        temp->next = stck.top();
        stck.pop();
        temp = temp->next;
    }
    temp->next = NULL;
}
void printReserveSize(ofstream& output) {
    output << "Reserve Size: " << checkSize(nodestack) << endl;
}
void convertReserve() {
    convertList("0", checkSize(nodestack), nodestack);
}
void printReserveTop(ofstream& output) {
    if (nodestack == NULL)
        return;
    else {
        output << "Top of Reserve: " << nodestack->fix << ":" << nodestack->data << endl;
    }
    output << endl;
}
int emptyReserve(int param) {
    int count = 0;
    int pos3 = param;
    while (nodestack != NULL) {
        if (param <= 0) {
            pos3 = 0;
        }
        else if (param > 0) {
            pos3 = checkSize(top);
        }
        popReserve(pos3);
        nodestack = nodestack->next;
    }
    return count;
}
void pop1()
{
    Node* temp;

    if (nodestack == NULL)
    {
        return;
    }
    else
    {
        temp = nodestack;
        nodestack = nodestack->next;
        temp->next = NULL;
        free(temp);
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


    string line, fix;
    string inid, inname, indiff, param, com;
    int count = 0;
    int size = 0;

    while (!inputFile.eof()) {
        getline(inputFile, fix, ':');
        getline(inputFile, line);
        line = removeSpaces(line);
        if (fix == "postfix") {
            add(top, line, fix);
        }
        else if (fix == "prefix") {
            add(top, line, fix);
        }
        size++;
    }
    ifstream commandFile;
    commandFile.open(command);
    string commandline;
    while (!commandFile.eof()) {
        Node* head = top;
        getline(commandFile, commandline);

        if (commandline.find("(") != std::string::npos) {
            param = paren(commandline);
            commandline = comm(commandline);
        }
        if (commandline == "convertList") {
            size = checkSize(top);
            convertList(param, size, top);
        }
        else if (commandline == "removeList") {
            size = checkSize(top);
            removeList(param, top, size);
        }
        else if (commandline == "printList") {
            size = checkSize(top);
            outputFile << "List:" << endl;
            if (top == NULL) {
                outputFile << "EMPTY" << endl;
                outputFile << endl;
            }
            else {

                printList(outputFile, top);
                outputFile << endl;
            }
        }
        else if (commandline == "printListBackwards") {
            size = checkSize(top);
            outputFile << "Reversed List: " << endl;
            printListBackwards(outputFile, top);
            outputFile << endl;
        }
        else if (commandline == "pushReserve") {
            size = checkSize(top);
            pushReserve(param, size);
        }
        else if (commandline == "popReserve") {
            size = checkSize(top);
            int pos1 = stoi(param);
            popReserve(pos1);
            pop1();
        }
        else if (commandline == "flipReserve") {
            size = checkSize(top);
            flipReserve();
        }
        else if (commandline == "printReserveSize") {
            size = checkSize(top);
            printReserveSize(outputFile);
            outputFile << endl;
        }
        else if (commandline == "convertReserve") {
            size = checkSize(top);
            convertReserve();
        }
        else if (commandline == "printReserveTop") {
            size = checkSize(top);
            printReserveTop(outputFile);
        }
        else if (commandline == "emptyReserve") {
            size = checkSize(top);
            int pos2 = stoi(param);
            int num = emptyReserve(pos2);
        }
    }
    commandFile.close();
    inputFile.close();
    outputFile.close();
}

