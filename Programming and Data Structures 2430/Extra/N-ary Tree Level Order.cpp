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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans = {};

        if (!root)
            return ans;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            vector<int> values;
            //Pick up the elements that are currently in the queue,
            //at that level.
            for (int i = 0; i < size; i++) {
                Node* temp = q.front();
                q.pop();
                values.push_back(temp->val);

                //Add children of the element(s) to the queue to 
                //process them at the next level.
                int num_child = temp->children.size();
                for (int j = 0; j < num_child; j++)
                    q.push(temp->children[j]);
            }
            ans.push_back(values);
        }
        return ans;
    }
};