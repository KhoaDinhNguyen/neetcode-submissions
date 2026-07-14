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
    bool ans = false;
    bool check(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr && subRoot == nullptr) return true;
        else if (root != nullptr && subRoot == nullptr) return false;
        else if (root == nullptr && subRoot != nullptr) return false;
        
        return root->val == subRoot->val && check(root->left, subRoot->left) && check(root->right, subRoot->right);
    }
    void dfs(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr) return;
        
        if (root != nullptr && subRoot != nullptr && root->val == subRoot->val) {
            ans = ans || check(root, subRoot);
        }

        dfs(root->left, subRoot);
        dfs(root->right, subRoot);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        dfs(root, subRoot);
        return ans;
    }
};
