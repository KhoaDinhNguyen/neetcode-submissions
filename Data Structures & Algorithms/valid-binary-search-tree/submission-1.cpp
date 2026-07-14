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
    int currVal = 0;
    bool res = true;
    void inOrder(TreeNode* root) {
        if (root != nullptr) {
            inOrder(root->left);
            if (root->val <= currVal) res = false;
            currVal = root->val;
            inOrder(root->right);
        }
    }
    bool isValidBST(TreeNode* root) {
        currVal = -1001;
        inOrder(root);

        return res;
    }
};
