/*
    GROUP WORK PERCENTAGES:
    Shaz Ali Momin: 33%
    Scott Tran: 33%
    Hugh Hoang: 33%
*/

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>

#include "ArgumentManager.h"

using namespace std;

struct GraphNode {
    int nextAttraction;
    int edgeWeight;
};

// Adds the attraction to the graph
void addAttractions(vector<GraphNode> attraction[], int v1, int v2, int edgeWeight) {
    GraphNode node;

    node.nextAttraction = v2;
    node.edgeWeight = edgeWeight;

    attraction[v1].push_back(node);

    node.nextAttraction = v1;

    attraction[v2].push_back(node);
}

// Checks to see if there is a valid path between each attraction
bool validPath(vector<GraphNode> attraction[], int current, bool nodeTraversed[], int count, int numVertices)
{
    int num = 0;
    for (int i = 0; i < numVertices; i++) {
        if (nodeTraversed[i]) {
            num += 1;
        }
        if (num == numVertices) {
            return true;
        }
    }

    for (int i = 0; i < attraction[current].size(); i++) {
        if (!nodeTraversed[attraction[current][i].nextAttraction]) {
            nodeTraversed[attraction[current][i].nextAttraction] = true;
            count++;
            return validPath(attraction, attraction[current][i].nextAttraction, nodeTraversed, count, numVertices);
            nodeTraversed[attraction[current][i].nextAttraction] = false;
            count--;
        }
    }
}


// Checks to see if there is a valid path between each attraction without going to an attraction more than once.
bool validSinglePath(vector<GraphNode> attraction[], int current, bool nodeTraversed[], int count, int numVertices)
{
    if (validPath(attraction, 0, nodeTraversed, count, numVertices) == false)
        return false;

    int edges = 0;
    for (int i = 0; i < numVertices; i++)
        if (attraction[i].size() & 1)
            edges++;

    if (edges > 2)
        return  false;


    if (edges == 2)
    {
        return true;
    }
    else if (edges == 0)
    {
        return false;
    }
}

// Returns the minimum length of cable needed to connect and power all attractions
int minimumLength(vector<GraphNode> attraction[], int numVertices) {
    bool nodeTraversed[numVertices];
    int totalWeight = 0;
    int nodeCounter = 1;
    int minWeight = attraction[0][0].edgeWeight;
    int edgeTracker = 0;

    nodeTraversed[0] = true;
    while (nodeCounter != numVertices) {
        for (int i = 0; i < numVertices; i++) {
            if (nodeTraversed[i]) {
                for (int j = 0; j < attraction[i].size(); j++) {
                    if (!nodeTraversed[attraction[i][j].nextAttraction]) {
                        if (minWeight > attraction[i][j].edgeWeight || minWeight == -1) {
                            edgeTracker = attraction[i][j].nextAttraction;
                            minWeight = attraction[i][j].edgeWeight;
                        }
                    }
                }
            }
        }

        totalWeight += minWeight;
        minWeight = -1;
        nodeTraversed[edgeTracker] = true;
        nodeCounter++;
    }

    return totalWeight;
}

// Will find which attractions have at least 3 attractions near it
void nearestAttractions(ofstream& outFile, vector<GraphNode> attraction[], int numVertices) {
    vector<GraphNode> nearAttract[numVertices];
    vector<int> head;
    int count, index = 0;

    for (int i = 0; i < numVertices; i++)
    {
        count = 0;

        for (GraphNode x : attraction[i]) {
            count++;
        }

        if (count >= 3) {
            nearAttract[index] = attraction[i];
            head.push_back(i);
            index++;
        }
    }

    outFile << "4. ";

    for (int i = 0; i < index; i++) {
        outFile << head[i] << "<-{";

        for (int j = 0; j < nearAttract[i].size(); j++) {
            if (j == nearAttract[i].size() - 1) {
                outFile << nearAttract[i][j].nextAttraction;
            }
            else {
                outFile << nearAttract[i][j].nextAttraction << ",";
            }
        }

        if (i == index - 1) {
            outFile << "}";
        }
        else {
            outFile << "}, ";
        }
    }

    outFile << endl;
}

// Final output according to the inputs
void printFile(ofstream& outFile, bool isValid, bool isValidSingle, int minLength, vector<GraphNode> attraction[], int numVertices) {
    if (isValid) {
        outFile << "1. Yes" << endl;

        if (isValidSingle) {
            outFile << "2. Yes" << endl;
        }
        else {
            outFile << "2. No" << endl;
        }

        outFile << "3. " << minLength << endl;

        nearestAttractions(outFile, attraction, numVertices);
    }
    else {
        outFile << "1. No" << endl;
    }

    if ((isValid) && (isValidSingle)) {
        outFile << "Good" << endl;
    }
    else if (isValid) {
        outFile << "Fair" << endl;
    }
    else {
        outFile << "Bad" << endl;
    }
}

void print(vector<GraphNode> attraction[], int size) {

    for (int i = 0; i < size; i++) {
        cout << i << "<-{";

        for (GraphNode x : attraction[i]) {
            cout << x.nextAttraction << " ";
        }

        cout << "}" << endl;
    }
}

int main(int argc, char* argv[]) {

    //Implementing Argument Manager
    ArgumentManager am(argc, argv);
    string input = am.get("input");
    string output = am.get("output");

    ifstream inFile(input);
    ofstream outFile(output);

    // Temporary file input and output (Change number to test another test case)
    // ifstream inFile("input32.txt");
    // ofstream outFile("output32.txt");

    //Code starts here
    int numVertices;
    int startVertex, endVertex;
    int edgeWeight;
    int size = 0;

    inFile >> numVertices;

    vector<GraphNode> attraction[numVertices];

    while (!inFile.eof()) {
        inFile >> startVertex;
        inFile >> endVertex;
        inFile >> edgeWeight;

        addAttractions(attraction, startVertex, endVertex, edgeWeight);
        size++;
    }
    inFile.close();

    bool nodeTraversed[numVertices];
    nodeTraversed[0] = true;
    bool isValidPath = validPath(attraction, 0, nodeTraversed, 1, numVertices);
    bool isValidSinglePath = validSinglePath(attraction, 0, nodeTraversed, 1, numVertices);
    int minLength = minimumLength(attraction, numVertices);

    printFile(outFile, isValidPath, isValidSinglePath, minLength, attraction, numVertices);

    return 0;
}