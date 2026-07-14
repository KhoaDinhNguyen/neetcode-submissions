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
    int temp(TreeNode* root) {
        if (root == nullptr) return 0;

        int leftDiameter = temp(root->left);
        int rightDiameter = temp(root->right);
        res = max(res, leftDiameter + rightDiameter);

        return 1 + max(leftDiameter, rightDiameter);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        temp(root);
    
        return res;
    }
};
