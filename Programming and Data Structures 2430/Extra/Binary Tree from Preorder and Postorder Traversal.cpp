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
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        if (pre.size() == 0 && post.size() == 0) {
            return NULL;
        }
        TreeNode* solve = new TreeNode(pre[0]);
        if (pre.size() == 1) {
            return solve;
        }
        int c = pre[1];
        vector<int>tmp;
        vector<int>tmp1;
        bool check = false;
        set<int>q;
        for (int i = 0; i < post.size() - 1; i++) {
            if (!check) {
                tmp.push_back(post[i]);
                q.insert(post[i]);
            }
            else {
                tmp1.push_back(post[i]);
            }
            if (c == post[i]) {
                check = true;
            }
        }
        vector<int>tmp2;
        vector<int>tmp3;
        for (int i = 1; i < pre.size(); i++) {
            if (q.find(pre[i]) != q.end()) {
                tmp2.push_back(pre[i]);
            }
            else {
                tmp3.push_back(pre[i]);
            }
        }
        solve->left = constructFromPrePost(tmp2, tmp);
        solve->right = constructFromPrePost(tmp3, tmp1);
        return solve;
    }
};