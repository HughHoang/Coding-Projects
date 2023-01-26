/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*> nodes;
        vector<vector<int>> ans;
        if (root)
            nodes.push(root);
        while (!nodes.empty()) {
            vector<int> temp;
            int size = nodes.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = nodes.front();
                temp.push_back(node->val);
                if (node->left)
                    nodes.push(node->left);
                if (node->right)
                    nodes.push(node->right);
                nodes.pop();
            }
            ans.push_back(temp);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};