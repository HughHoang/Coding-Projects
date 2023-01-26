/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
        if (root == NULL)
            return {};

        stack<Node*> dfs;
        dfs.push(root);

        vector<int> result;
        Node* curr = NULL;

        while (!dfs.empty()) {
            curr = dfs.top();
            dfs.pop();

            result.push_back(curr->val);

            for (auto itr = curr->children.begin(); itr != curr->children.end(); ++itr) {
                dfs.push(*itr);
            }
        }

        reverse(result.begin(), result.end());
        return result;
    }
};