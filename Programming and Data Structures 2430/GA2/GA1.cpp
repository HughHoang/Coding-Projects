#include <iostream>
#include <fstream>
#include <string>
#include <vector>   
#include <iomanip>
#include "ArgumentManager.h"
#include <stack>
using namespace std;

//John Pruitt:0%  Hugh Hoang:570%  //Zitlali Silva: 30%
class Node {
public:
    int data;
    Node* next;
};
Node* SortedMerge(Node* a, Node* b)
{
    Node* result = NULL;

    if (a == NULL)
        return(b);
    else if (b == NULL)
        return(a);

    if (a->data <= b->data)
    {
        result = a;
        result->next = SortedMerge(a->next, b);
    }
    else
    {
        result = b;
        result->next = SortedMerge(a, b->next);
    }
    return(result);
}
int precedence(char c) {
    switch (c) {
    case '+':
        return 1;
        break;
    case '-':
        return 1;
        break;
    case '*':
        return 2;
        break;
    case '/':
        return 2;
        break;
    case '^':
        return 3;
        break;
    }
    return 0;
}
string infixToPostfix(string s) {
    stack<char> st;
    string postfixString = "";

    for (int i = 0; i < s.length(); i++) {
        if (isdigit(s[i])) {
            postfixString += s[i];
        }
        else if (s[i] == '(') {
            st.push(s[i]);
        }
        else if (s[i] == ')') {
            while (st.top() != '(') {
                postfixString += st.top();
                st.pop();
            }
            st.pop();
        }
        else if (s[i] == '[') {
            st.push(s[i]);
        }
        else if (s[i] == ']') {
            while (st.top() != '[') {
                postfixString += st.top();
                st.pop();
            }
            st.pop();
        }
        else if (s[i] == '{') {
            st.push(s[i]);
        }
        else if (s[i] == '}') {
            while (st.top() != '{') {
                postfixString += st.top();
                st.pop();
            }
            st.pop();
        }

        else {
            while (!st.empty() && precedence(st.top()) >= precedence(s[i])) {
                postfixString += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while (!st.empty()) {
        postfixString += st.top();
        st.pop();
    }

    return postfixString;
}
int operate(int a, int b, char oper) {
    switch (oper) {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    }
    return 0;
}
int evaluatePostfix(string s) {
    stack<int> st;
    for (int i = 0; i < s.length(); i++) {
        if (isdigit(s[i])) {
            st.push((int)s[i] - 48);
        }
        else {
            int right = st.top();
            st.pop();
            int left = st.top();
            st.pop();
            int ans = operate(left, right, s[i]);
            st.push(ans);
        }
    }

    return st.top();
}
bool isBalanced(string expression) {
    stack<char> stk; char x;
    int firstcount = 0;
    int bcount = 0;
    for (int j = 0; j < expression.length(); j++) {
        if (expression[j] == '(' || expression[j] == '{' || expression[j] == '[') {
            firstcount = j;
            break;
        }
    }
    for (int k = 0; k < expression.length(); k++) {
        if (expression[k] == ')' || expression[k] == '}' || expression[k] == ']') {
            bcount = k;
            break;
        }
    }
    if ((firstcount == 0) && (bcount == 0)) {
        return true;
    }
    for (int i = firstcount; i < expression.length(); i++) {

        if (expression[i] == '(' || expression[i] == '{' || expression[i] == '[') {
            stk.push(expression[i]);
            continue;
        }

        switch (expression[i]) {
        case '}':
            x = stk.top();
            stk.pop();
            if (x == '[' || x == '(')
                return false;
            break;

        case ']':
            x = stk.top();
            stk.pop();
            if (x == '(' || x == '{')
                return false;
            break;

        case ')':
            x = stk.top();
            stk.pop();
            if (x == '[' || x == '{')
                return false;
            break;
        }
    }
    return (stk.empty());
}
Node* add(Node* head, int data)
{
    Node* temp = new Node;
    temp->data = data;
    temp->next = NULL;
    if (head == NULL)
        return temp;

    else
        head->next = add(head->next, data);
    return head;
}
void display(ofstream& output, Node* head1, Node* head2, Node* passnode, string passcode)
{
    Node* Scarlet;
    Scarlet = head1;
    Node* Travis;
    Travis = head2;
    Node* passNode;
    passNode = passnode;

    output << "Scarlet: [";
    if (Scarlet == nullptr) {

    }
    else {
        output << Scarlet->data;
        Scarlet = Scarlet->next;
        while (Scarlet != nullptr)
        {
            output << "," << Scarlet->data;
            Scarlet = Scarlet->next;
        }
    }
    output << "]" << endl;
    output << "Travis: [";
    if (Travis == nullptr) {

    }
    else {
        output << Travis->data;
        Travis = Travis->next;
        while (Travis != nullptr)
        {
            output << "," << Travis->data;
            Travis = Travis->next;
        }
    }
    output << "]" << endl;
    output << "Decoded passcode: | ";
    int count = passcode.length();

    while (passNode != nullptr)
    {
        output << passNode->data << " | ";
        passNode = passNode->next;
    }

    output << endl;
    output << "Actual passcode: | ";
    for (int i = 0; count > i; i++) {
        output << passcode.at(i);
        output << " | ";
    }
    output << endl;
    output << "Treasure unlocked!";
}
Node* sort(Node* head) {
    if (head == NULL || head->next == NULL)
        return head;

    int max = head->data;
    Node* prev = head;
    Node* move = NULL;
    Node* tmp = head->next;

    while (tmp != NULL) {
        if (tmp->data < max) {
            max = tmp->data;
            move = prev;
        }
        prev = tmp;
        tmp = tmp->next;
    }

    if (move == NULL) {
        head->next = sort(head->next);
        return head;
    }

    prev = move;
    move = prev->next;
    prev->next = prev->next->next;
    move->next = sort(head);
    return move;
}
int findpos(Node* head, int n, int pos)
{
    if (head == nullptr)
        return -1;

    if (head->data == n)
    {
        return pos;
    }

    int out = findpos(head->next, n, pos + 1);
    return out;
}

Node* del(Node* start, int num)
{
    if (num < 1)
        return start;

    if (start == NULL)
        return NULL;

    if (num == 1)
    {
        Node* res = start->next;
        delete(start);
        return res;
    }

    start->next = del(start->next, num - 1);
    return start;
}
bool search(Node* head, int x)
{
    if (head == NULL)
        return false;

    if (head->data == x)
        return true;

    return search(head->next, x);
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

    string name;
    string equation;
    int outCompute;
    string line;
    string passcode;
    int noutCompute;
    int count = 0;
    int bal = 0;
    int pos;

    Node* Scarlet = NULL;
    Node* Travis = NULL;
    Node* passnode = NULL;
    Node* tempScarlet = NULL;
    Node* tempTravis = NULL;
    vector<int> Tvec;
    vector<int> Svec;

    while (!inputFile.eof()) {
        getline(inputFile, line);
        while (line.length() == 0) {
            getline(inputFile, line);
        }
        if (line == "Scarlet") {
            name = "Scarlet";
        }
        else if (line == "Travis") {
            name = "Travis";
        }
        else if (line.find("Passcode:") != std::string::npos) {
            passcode = line;
            passcode.erase(0, 9);
        }
        else {
            if (isBalanced(line)) {
                string postfix = infixToPostfix(line);
                int outCompute = evaluatePostfix(postfix);
                if (name == "Scarlet") {
                    if (outCompute >= 0) {
                        Scarlet = add(Scarlet, outCompute);
                        tempScarlet = add(tempScarlet, outCompute);
                    }
                    else {
                        noutCompute = outCompute * -1;
                        Svec.push_back(noutCompute);
                    }
                }
                else if (name == "Travis") {

                    if (outCompute >= 0) {
                        Travis = add(Travis, outCompute);
                        tempTravis = add(tempTravis, outCompute);
                    }
                    else {
                        noutCompute = outCompute * -1;
                        Tvec.push_back(noutCompute);
                    }
                }
            }
            else {
                bal++;
            }
        }
    }
    for (int i = 0; i < Svec.size(); i++) {
        //cout << Svec.at(i);
        if (search(Scarlet, Svec.at(i))) {
            pos = 1 + findpos(Scarlet, Svec.at(i), 0);
            Scarlet = del(Scarlet, pos);
            tempScarlet = del(tempScarlet, pos);

        }
        else if (search(Travis, Svec.at(i))) {
            pos = 1 + findpos(Travis, Svec.at(i), 0);
            Travis = del(Travis, pos);
            tempTravis = del(tempTravis, pos);
        }
    }

    for (int i = 0; i < Tvec.size(); i++) {
        //cout << Tvec.at(i);
        if (search(Travis, Tvec.at(i))) {
            pos = 1 + findpos(Travis, Tvec.at(i), 0);
            Travis = del(Travis, pos);
            tempTravis = del(tempTravis, pos);
        }
        else if (search(Scarlet, Tvec.at(i))) {
            pos = 1 + findpos(Scarlet, Tvec.at(i), 0);
            Scarlet = del(Scarlet, pos);
            tempScarlet = del(tempScarlet, pos);
        }
    }
    Scarlet = sort(Scarlet);
    Travis = sort(Travis);
    passnode = SortedMerge(Scarlet, Travis);
    if (bal == 0) {

    }
    else {
        passnode = del(passnode, bal + 1);
    }
    display(outputFile, tempScarlet, tempTravis, passnode, passcode);
    inputFile.close();
    outputFile.close();

}

