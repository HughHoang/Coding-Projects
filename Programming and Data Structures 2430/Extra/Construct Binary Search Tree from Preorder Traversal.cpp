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
    map<int, int>m;
    TreeNode* bstFromPreorderUtil(vector<int>& preorder, vector<int>& inorder, int l, int r, int k)
    {
        if (l > r) return NULL;

        int mid, data = preorder[k];
        mid = m[data];

        TreeNode* root = new TreeNode(data);

        root->left = bstFromPreorderUtil(preorder, inorder, l, mid - 1, k + 1);
        root->right = bstFromPreorderUtil(preorder, inorder, mid + 1, r, k + mid - l + 1);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder)
    {
        int n = preorder.size() - 1;
        vector<int>inorder = preorder;

        sort(inorder.begin(), inorder.end());

        for (int i = 0; i <= n; i++) {
            m[inorder[i]] = i;
        }
        return bstFromPreorderUtil(preorder, inorder, 0, n, 0);
    }
};