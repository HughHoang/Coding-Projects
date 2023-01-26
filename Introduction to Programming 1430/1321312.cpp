#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    // val is the key or the value that 
    // has to be added to the data part 
    Node(int val)
    {
        data = val;

        // Left and right child for node 
        // will be initialized to null 
        left = NULL;
        right = NULL;
    }
};
vector<int> rightSideView(Node* root)
{
    vector<int> visable;

    if (root == nullptr)
    {
        return visable;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            Node* current = q.front();
            q.pop();

            if (i == size - 1)
            {
                visable.push_back(current->data);
            }

            if (current->left)
            {
                q.push(current->left);
            }

            if (current->right)
            {
                q.push(current->right);
            }
        }
    }

    return visable;
}
int main()
{

    /*create root*/
    struct Node* root = new Node(1);
    /* following is the tree after above statement

             1
            / \
            NULL NULL
    */

    root->left = new Node(2);
    root->right = new Node(3);
    /* 2 and 3 become left and right children of 1
                    1
                    / \
                   2     3
                  / \    /  \
               NULL NULL NULL NULL
    */
    root->right->right = new Node(4);
    root->left->right = new Node(5);

    /* 4 becomes left child of 2
               1
            /     \
            2      3
            / \     / \
    4 NULL NULL NULL
    / \
    NULL NULL
    */
    rightSideView(root);
    return 0;
}