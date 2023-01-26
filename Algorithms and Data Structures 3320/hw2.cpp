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
        int id;
        string name;
        string difficulty;

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
    void add(int _id, string _name, string _difficulty, int pos);
    int countNode(node* head);
    void removebypos(int pos);
    void removebyid(int id);
    void removebyname(string name);
    void removebydiff(string diff);
    void sort(string sortby, string direction);
    void swap(struct node* a, struct node* b);
    void display(ofstream& output);
    void addinput(int intid, string inname, string indiff);
};

void Problem::addinput(int intid, string inname, string indiff) {
    node* tmp = new node;
    tmp->id = intid;
    tmp->name = inname;
    tmp->difficulty = indiff;
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

void Problem::add(int _id, string _name, string _difficulty, int pos)
{

    {
        struct node* temp, * cur;
        temp = new node();
        temp->id = _id;
        temp->name = _name;
        temp->difficulty = _difficulty;

        temp->next = NULL;
        cur = head;
        if (pos > size) {
            pos = size;
        }
        if (pos == 0) {
            head = nullptr;
            addinput(_id, _name, _difficulty);
            return;
        }
        while (cur != nullptr)
        {
            if (cur->id == _id) {
                return;
            }
            cur = cur->next;
        }

        struct node* n;
        n = new node;
        struct node* n1;
        n1 = new node;
        n->id = _id;
        n-> name = _name;
        n->difficulty = _difficulty;
        n->next = nullptr;
        if (head == nullptr)
        {
            n->next = head;
            head = n;
            return;
        }
        else
        {
            n1 = head;
            for (int i = 0; i < pos; i++)
            {
                n1 = n1->next;
            }
            n->next = n1->next;
            n1->next = n;
            return;
        }
    }
        size++;
}
void Problem::removebyid(int id)
{
    node* current = head, * first = head;

    if (size == 1)
    {
        delete current;
        size--;
        return;
    }

    node* next = head->next;

    while (current->id == id)
    {
        delete current;
        current = next;
        next = current->next;
    }
    first = current;

    while (next != NULL)
    {
        if (next->id == id)
        {
            current->next = next->next;
            delete next;
            next = current->next;
        }
        else {
            current = next;
            next = next->next;
        }
    }
    size--;

}
void Problem::removebypos(int pos) {

    int count = 0;
    node* temp, * temp1, * temp2;
    temp = head;
    if (size < pos) {
        return;
    }
    if (head == NULL) {
        return;
    }
    else if (pos == 0)
    {
        head = head->next;
        free(temp);
    }
    else {
        while (count != pos - 1)
        {
            temp = temp->next;
            count++;
        }
        temp1 = temp->next;
        temp->next = temp1->next;

        free(temp1);
    }

    size--;
}
void Problem::removebyname(string name) {

    node* current = head, * first = head, * next = head->next;
    while (current->name == name)
    {
        delete current;
        current = next;
        next = current->next;
    }
    first = current;

    while (next != NULL)
    {
        if (next->name == name)
        {
            current->next = next->next;
            delete next;
            next = current->next;
            size--;
        }
        else {
            current = next;
            next = next->next;
        }
    }

}
void Problem::removebydiff(string diff) {

    node* current = head, * first = head, * next = head->next;
    while (current->difficulty == diff)
    {
        delete current;
        current = next;
        next = current->next;
    }
    first = current;

    while (next != NULL)
    {
        if (next->difficulty == diff)
        {
            current->next = next->next;
            delete next;
            next = current->next;
        }
        else {
            current = next;
            next = next->next;
        }
    }
    size--;
}
void Problem::sort(string sortby, string direction)
{

    if (head == NULL) {
        return;
    }
    if (sortby == "problem_id") {
        if (direction == "decreasing") {
            node* temphead = head;
            int tempid;
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
                    if (temphead->id < temphead->next->id)
                    {
                        tempid = temphead->id;
                        temphead->id = temphead->next->id;
                        temphead->next->id = tempid;

                        tempname = temphead->name;
                        temphead->name = temphead->next->name;
                        temphead->next->name = tempname;

                        tempdifficulty = temphead->difficulty;
                        temphead->difficulty = temphead->next->difficulty;
                        temphead->next->difficulty = tempdifficulty;
                    }
                    temphead = temphead->next;
                }
                temphead = head;
            }
        }
        else if (direction == "increasing") {
            node* temphead = head;
            int tempid;
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
                    if (temphead->id > temphead->next->id)
                    {
                        tempid = temphead->id;
                        temphead->id = temphead->next->id;
                        temphead->next->id = tempid;

                        tempname = temphead->name;
                        temphead->name = temphead->next->name;
                        temphead->next->name = tempname;

                        tempdifficulty = temphead->difficulty;
                        temphead->difficulty = temphead->next->difficulty;
                        temphead->next->difficulty = tempdifficulty;
                    }
                    temphead = temphead->next;
                }
                temphead = head;
            }
        }
    }
    if (sortby == "problem_name") {
        if (direction == "decreasing") {
            node* temphead = head;
            int tempid;
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
                    if (temphead->name < temphead->next->name)
                    {
                        tempid = temphead->id;
                        temphead->id = temphead->next->id;
                        temphead->next->id = tempid;

                        tempname = temphead->name;
                        temphead->name = temphead->next->name;
                        temphead->next->name = tempname;

                        tempdifficulty = temphead->difficulty;
                        temphead->difficulty = temphead->next->difficulty;
                        temphead->next->difficulty = tempdifficulty;
                    }
                    temphead = temphead->next;
                }
                temphead = head;
            }
        }
        else if (direction == "increasing") {
            node* temphead = head;
            int tempid;
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
                    if (temphead->name > temphead->next->name)
                    {
                        tempid = temphead->id;
                        temphead->id = temphead->next->id;
                        temphead->next->id = tempid;

                        tempname = temphead->name;
                        temphead->name = temphead->next->name;
                        temphead->next->name = tempname;

                        tempdifficulty = temphead->difficulty;
                        temphead->difficulty = temphead->next->difficulty;
                        temphead->next->difficulty = tempdifficulty;
                    }
                    temphead = temphead->next;
                }
                temphead = head;
            }
        }
    }
    if (sortby == "difficulty") {
        if (direction == "decreasing") {
            node* temphead = head;
            int tempid;
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
                    string test = temphead->difficulty;
                    string test1 = temphead->next->difficulty;
                    int diff = 0, diff1 = 0;
                    if (test == "Easy") {
                        diff = 1;
                    }
                    else if (test == "Medium") {
                        diff = 2;
                    }
                    else if (test == "Hard") {
                        diff = 3;
                    }
                    if (test1 == "Easy") {
                        diff1 = 1;
                    }
                    else if (test1 == "Medium") {
                        diff1 = 2;
                    }
                    else if (test1 == "Hard") {
                        diff1 = 3;
                    }
                    if (diff == diff1) {
                        tempid = temphead->next->id;
                        temphead->next->id = temphead->id;
                        temphead->id = tempid;

                        tempname = temphead->name;
                        temphead->name = temphead->next->name;
                        temphead->next->name = tempname;

                        tempdifficulty = temphead->difficulty;
                        temphead->difficulty = temphead->next->difficulty;
                        temphead->next->difficulty = tempdifficulty;
                    }
                    if (diff < diff1)
                    {
                        tempid = temphead->id;
                        temphead->id = temphead->next->id;
                        temphead->next->id = tempid;

                        tempname = temphead->name;
                        temphead->name = temphead->next->name;
                        temphead->next->name = tempname;

                        tempdifficulty = temphead->difficulty;
                        temphead->difficulty = temphead->next->difficulty;
                        temphead->next->difficulty = tempdifficulty;
                    }
                    temphead = temphead->next;
                }
                temphead = head;
            }

        }
        else if (direction == "increasing") {
            node* temphead = head;
            int tempid;
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
                    string test = temphead->difficulty;
                    string test1 = temphead->next->difficulty;
                    if (test == "Easy") {
                        test = 1;
                    }
                    if (test == "Medium") {
                        test = 2;
                    }
                    if (test == "Hard") {
                        test = 3;
                    }
                    if (test1 == "Easy") {
                        test1 = 1;
                    }
                    if (test1 == "Medium") {
                        test1 = 2;
                    }
                    if (test1 == "Hard") {
                        test1 = 3;
                    }

                    if (test > test1)
                    {
                        tempid = temphead->id;
                        temphead->id = temphead->next->id;
                        temphead->next->id = tempid;

                        tempname = temphead->name;
                        temphead->name = temphead->next->name;
                        temphead->next->name = tempname;

                        tempdifficulty = temphead->difficulty;
                        temphead->difficulty = temphead->next->difficulty;
                        temphead->next->difficulty = tempdifficulty;
                    }
                    temphead = temphead->next;
                }
                temphead = head;
            }
        }
    }

}

void Problem::display(ofstream& output)
{
    struct node* temp = head;
    if (size == 0) {
        return;
    }
    if (size == 1) {
        output << "problem_id:" << temp->id << ", problem_name :" << temp->name << ", difficulty:" << temp->difficulty << endl;
    }
    else
    {
        while (temp != NULL) {
            output << "problem_id:" << temp->id << ", problem_name :" << temp->name << ", difficulty:" << temp->difficulty << endl;
            temp = temp->next;
        }
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

    Problem Llist;

    string line;
    string inid, inname, indiff;
    int count = 0;

    while (!inputFile.eof()) {
        getline(inputFile, line, ':');
        getline(inputFile, inid, ',');
        getline(inputFile, line, ':');
        getline(inputFile, inname, ',');
        getline(inputFile, line, ':');
        getline(inputFile, indiff, '\n');
        int intid = stoi(inid);
        Llist.addinput(intid, inname, indiff);
    }
    ifstream commandFile;
    commandFile.open(command);
    string direction, commandline, commdiff, commname, type, commandinput, remove, removetype;
    int pos, commid;
    while (!commandFile.eof()) {
        commandFile >> commandline;
        if (commandline == "sort") {
            commandFile >> type;
            commandFile >> direction;

            Llist.sort(type, direction);
        }
        else if (commandline == "add") {
            getline(commandFile, line, ':');
            commandFile >> pos;
            getline(commandFile, line, ':');
            commandFile >> commid;
            getline(commandFile, line, ':');
            getline(commandFile, commname, ',');
            getline(commandFile, line, ':');
            getline(commandFile, commdiff, '\n');
            Llist.add(commid, commname, commdiff, pos - 1);
        }
        else if (commandline == "remove") {

            getline(commandFile, removetype, ':');
            commandFile >> remove;
            if (removetype == " pos") {
                int removepos = stoi(remove);
                Llist.removebypos(removepos);
            }
            else if (removetype == " difficulty") {
                Llist.removebydiff(remove);
            }
            else if (removetype == " problem_name") {
                Llist.removebyname(remove);
            }
            else if (removetype == " problem_id") {
                int removeid = stoi(remove);
                Llist.removebyid(removeid);
            }
        }
    }
    Llist.display(outputFile);
    commandFile.close();
    inputFile.close();
    outputFile.close();
}
