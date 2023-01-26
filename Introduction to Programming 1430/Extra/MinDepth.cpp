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
	int maxDepth(TreeNode* root) {
		if (root == NULL)
			return 0;
		queue<TreeNode*> q;
		q.push(root);
		int height = 0;
		while (!q.empty())
		{
			int count = q.size();
			while (count)
			{
				TreeNode* ft = q.front();
				q.pop();
				if (ft->left != NULL)
					q.push(ft->left);
				if (ft->right != NULL)
					q.push(ft->right);
				count--;
			}
			height++;
		}
		return height;
	}
};