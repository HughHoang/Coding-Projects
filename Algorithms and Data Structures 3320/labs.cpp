#include "ArgumentManager.h"
#include <iostream>
#include <fstream>
#include <vector>


struct node;

struct graph {
    int vertices = 0;
    int edges = 0;
};

struct edge {
    int size = -1;
    node* v1 = nullptr;
    node* v2 = nullptr;
};

struct node {
    int id = -1;
    bool visited = false;
    vector <edge> connect;
};


edge addEdge(node*, node*, int);
void BFord(vector<edge>, int, int, ofstream&, graph);
void printArr(vector<int>, int, ofstream&);

int main(int argc, char* argv[])
{
    ArgumentManager am(argc, argv);
    string input = am.get("input");
    string output = am.get("output");

    input = "input3.txt";
    output = "output3.txt";

    ifstream in(input);
    ofstream out(output);

    int num_vertices, edges, start, finish;
    int num, check, dist, count;
    bool dupe1 = false;
    bool dupe2 = false;

    node* init = new node;

    count = 0;

    in >> num_vertices >> edges >> start >> finish;
    vector<node*> ids(num_vertices, nullptr);
    vector<edge> graph_edges;
    multimap<node*, node*> vertices;
    node* source = new node;

    graph tree;
    tree.edges = edges;
    tree.vertices = num_vertices;

    for (int i = 0; i < edges; i++) {//iterate through each line to make nodes and store in array
        dupe1 = false;
        dupe2 = false;
        in >> num >> check >> dist;
        if (ids[0] == nullptr) {//checks if array is empty
            node* temp = new node;
            init->id = num;
            temp->id = check;
            ids[count] = init;
            ids[count + 1] = temp;
            //connection goes here
            edge new_edge = addEdge(init, temp, dist);
            graph_edges.push_back(new_edge);

            count += 2;
            continue;
        }

        for (int j = 0; j < num_vertices; j++) {//iterates through array to find duplicates
            if (ids[j] == nullptr) { break; }
            else if (ids[j]->id == check) {//if there is no node with id of 2nd num
                dupe2 = true;
            }
            else if (ids[j]->id == num) {
                dupe1 = true;
            }

        }

        if (dupe1 == true && dupe2 == true) {
            node* v1 = ids[num - 1];
            node* v2 = ids[check - 1];

            if (v1 == nullptr || v2 == nullptr) {
                continue;
            }
            else {
                edge new_edge = addEdge(v1, v2, dist);
                graph_edges.push_back(new_edge);
            }
        }
        else {
            node* v1 = new node;
            node* v2 = new node;

            if (dupe1) {
                v1 = ids[num - 1];
                v2->id = check;
                edge new_edge = addEdge(v1, v2, dist);
                graph_edges.push_back(new_edge);
                ids[check - 1] = v2;
            }
            else if (dupe2) {
                v1->id = num;
                v2 = ids[check - 1];
                edge new_edge = addEdge(v1, v2, dist);
                graph_edges.push_back(new_edge);
                ids[num - 1] = v1;
            }
        }
        
        for (int i = 0; i < num_vertices; i++) {
            if (ids[i] == nullptr) {
                continue;
            }
            else if (ids[i]->id == start) {
                source = ids[i];
                break;
            }
        }

    }

    BFord(graph_edges, finish, start, out, tree);
    return 0;
}

edge addEdge(node* vertice1, node* vertice2, int size) {
    edge temp;
    temp.v1 = vertice1;
    temp.v2 = vertice2;
    temp.size = size;
    vertice1->connect.push_back(temp);
    temp.v1 = vertice2;//flips edge
    temp.v2 = vertice1;
    vertice2->connect.push_back(temp);
    temp.v1 = vertice1;
    temp.v2 = vertice2;
    return temp;
}

void BFord(vector<edge> ed, int end, int start, ofstream& out, graph g) {
    int v = g.vertices + 1;
    int e = g.edges;
    vector <int> dist (v, 9999);

    dist[start] = 0;

    for (int i = 1; i < v - 1; i++) {
        for (int j = 0; j < e; j++) {
            int a = ed[j].v1->id;
            int b = ed[j].v2->id;
            if (dist[a] != 9999 && dist[a] + ed[j].size < dist[b]) {
                dist[b] = dist[a] + ed[j].size;
            }
            else if (dist[b] != 9999 && dist[b] + ed[j].size < dist[a]) {
                dist[a] = dist[b] + ed[j].size;
            }
        }
    }

    for (int i = 0; i < e; i++) {
        int a = ed[i].v1->id;
        int b = ed[i].v2->id;
        if (dist[a] != 9999 && dist[a] + ed[i].size < dist[b]) {
            return;
        }
        if (dist[b] != 9999 && dist[b] + ed[i].size < dist[a]) {
            return;
        }
    }

    printArr(dist, end, out);

}

void printArr(vector<int> dist, int end, ofstream& out) {
    for (int i = 0; i < dist.size(); i++) {
        if (i == 0) { continue; }
        if (dist[i] == 0) {
            out << dist[end] << endl;
            break;
        }
    }
}