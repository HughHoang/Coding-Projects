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
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> ans;
        vector<int> v;
        int count = 1;

        if (root == NULL)
            return ans;

        queue<TreeNode*>q;
        q.push(root);

        while (!q.empty()) {
            root = q.front();
            v.push_back(root->val);
            q.pop();
            count--;

            if (root->left)
                q.push(root->left);
            if (root->right)
                q.push(root->right);

            if (count == 0) {
                count = q.size();
                ans.push_back(v);
                v.clear();
            }
        }

        return ans;

    }
};