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
    int k = 0;
    unordered_map<int, int> indices;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int l, int r) {
        if (l > r) {
            return nullptr;
        }

        int temp = preorder[k++];

        TreeNode* node = new TreeNode(temp);

        int idx = indices[temp];

        node->left = buildTree(preorder, inorder, l, idx - 1);
        node->right = buildTree(preorder, inorder, idx + 1, r);

        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); ++i) {
            indices[inorder[i]] = i;
        }
        return buildTree(preorder, inorder, 0, inorder.size() - 1);
    }

    // time O(N)
    // space O(N)
};
