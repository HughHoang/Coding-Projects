#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <queue>

using namespace std;

struct Tree {
    int num;
    string letters;
    Tree* left;
    Tree* right;
};

class BinaryTree {
private:
    Tree* root;

public:
    BinaryTree() {
        root = nullptr;
    }
    Tree* returnRoot() {
        return root;
    }
    void setRoot(Tree* inroot) {
        root = inroot;
    }
    // Adds a node to the binary tree
    Tree* addNode(Tree* root, string letter, int value) {

        if (root == NULL) {
            Tree* temp = new Tree;
            temp->num = value;
            temp->letters = letter;
            temp->left = temp->right = NULL;
            return temp;
        }

        if (value < root->num)
            root->left = addNode(root->left, letter, value);

        else if (value >= root->num)
            root->right = addNode(root->right, letter, value);

        return root;
    }
    
    void printLevelOrder(Tree* root)
    {
        // Base Case  
        if (root == NULL) return;

        // Create an empty queue for level order tarversal  
        queue<Tree* > q;

        // Enqueue Root and initialize height  
        q.push(root);

        while (q.empty() == false)
        {
            // nodeCount (queue size) indicates number 
            // of nodes at current lelvel.  
            int nodeCount = q.size();

            // Dequeue all nodes of current level and  
            // Enqueue all nodes of next level  
            while (nodeCount > 0)
            {
                Tree* node = q.front();
                
                q.pop();
                if (node->left != NULL)
                    q.push(node->left);
                if (node->right != NULL)
                    q.push(node->right);
                nodeCount--;
            }
        }
    }
    // Finds the distance of a given number in the Binary Tree from the root
    int findDistanceOfNode(string letters) {
        Tree* current = root;
        int distance = 1;
        int value = 0;

        for (int i = 0; i < letters.length(); i++) {
            value += letters[i];
        }

        while (letters != current->letters) {
            if (value < current->num) {
                current = current->left;
            }
            else {
                current = current->right;
            }
            distance++;
        }

        return distance;
    }
};