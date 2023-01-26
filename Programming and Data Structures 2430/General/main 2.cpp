#include <iostream>

using namespace std;

// node stuff
struct Node
{
    int val;
    Node* left;
    Node* right;
    Node(int val);
};

Node::Node(int val)
: val(val), left(nullptr), right(nullptr)
{
}

// bst functions
Node* insert(Node* root, int val)
{
    if (root == nullptr)
    {
        Node* newNode = new Node(val);
        root = newNode;
    }
    else if (val < root->val)
    {
        root->left = insert(root->left, val);
    }
    else if (val > root->val)
    {
        root->right = insert(root->right, val);
    }

    return root;
}

void preOrder(Node* root)
{
    if (root != nullptr)
    {
        cout << root->val << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(Node* root)
{
    if (root != nullptr)
    {
        inOrder(root->left);
        cout << root->val << " ";
        inOrder(root->right);
    }
}

void postOrder(Node* root)
{
    if (root != nullptr)
    {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->val << " ";
    }
}

int countNodes(Node* root)
{
    if (root == nullptr)
    {
        return 0;
    }

    int leftNodes = countNodes(root->left);
    int rightNodes = countNodes(root->right);

    return leftNodes + rightNodes + 1;
}



int main()
{
    Node* root = nullptr;
    root = insert(root, 5);
    insert(root, 6);
    insert(root, 3);
    insert(root, 2);

    cout << countNodes(root);

    return 0;
}