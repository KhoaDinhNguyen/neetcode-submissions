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
    vector<int> res;

    void bfs(TreeNode* root) {
        if (root == nullptr) return;

        queue<TreeNode*> q;
        q.push(root);

        res.push_back(q.back()->val);

        while (!q.empty()) {
            int m = q.size();

            for (int i = 0; i < m; ++i) {
                TreeNode* curr = q.front();

                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);

                q.pop();
            }

            if (q.size() > 0) {
                res.push_back(q.back()->val);
            }
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) return {};

        bfs(root);

        return res;
    }
};
