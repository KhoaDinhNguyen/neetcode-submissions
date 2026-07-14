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
    int res = 0;

    void dfs(TreeNode* root, int currMax) {
        if (root == nullptr) return;

        if (root->val >= currMax) res++;

        dfs(root->left, max(currMax, root->val));
        dfs(root->right, max(currMax, root->val));
    }
    int goodNodes(TreeNode* root) {
        dfs(root, -101);

        return res;
    }
};
