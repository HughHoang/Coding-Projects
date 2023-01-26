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
	bool isSameTree(TreeNode* p, TreeNode* q) {
		queue<TreeNode*> qe1, qe2;
		qe1.push(p);
		qe2.push(q);
		while (!qe1.empty() && !qe2.empty()) {
			TreeNode* n1 = qe1.front();
			TreeNode* n2 = qe2.front();
			qe1.pop();
			qe2.pop();
			if (n1 == NULL && n2 == NULL) {
				continue;
			}
			if (n1 == NULL || n2 == NULL) {
				return false;
			}
			if (n1->val != n2->val) {
				return false;
			}
			qe1.push(n1->left);
			qe1.push(n1->right);
			qe2.push(n2->left);
			qe2.push(n2->right);
		}
		if (!qe1.empty() || !qe2.empty()) {
			return false;
		}
		return true;
	}
};