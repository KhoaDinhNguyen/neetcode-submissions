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
    int ans = 0;
    void preorder(TreeNode* root, int currMax) {
        if (root) {
            if (root->val >= currMax) {
                ans++;
            }
            preorder(root->left, max(currMax, root->val));
            preorder(root->right, max(currMax, root->val));
        }
    }
    int goodNodes(TreeNode* root) {
        preorder(root, -100000);

        return ans;
    }
};
