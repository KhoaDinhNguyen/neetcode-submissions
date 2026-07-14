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

class Codec {
public:
    void buildTree(TreeNode* root, string encode, int val) {
        int N = encode.size();

        TreeNode* curr = root;

        for (int i = 0; i < N - 1; ++i) {
            if (encode[i] == 'l') curr = curr->left;
            else curr = curr->right;
        }

        if (encode[N - 1] == 'l') curr->left = new TreeNode(val);
        else curr->right = new TreeNode(val);
    }

    void preorder(TreeNode* root, string currEncode, vector<pair<string, int>>& store) {
        if (root) {
            store.push_back(make_pair(currEncode, root->val));
            preorder(root->left, currEncode + "l", store);
            preorder(root->right, currEncode + "r", store);
        }
    }

    vector<pair<string,int>> decodeString(string data) {
        string encode = "", numString = "";
        vector<pair<string, int>> res;

        int i = 0;

        for (; i < data.size(); ++i) {
            if (data[i] == '|') {
                i++;
                break;
            }
            else numString += data[i];
        }

        res.push_back(make_pair("", stoi(numString)));
        numString = "";

        for (; i < data.size(); ++i) {
            if (data[i] == '|') {
                res.push_back(make_pair(encode, stoi(numString)));
                encode = "";
                numString = "";
            }
            else if (data[i] == 'l' || data[i] == 'r') encode += data[i];
            else numString += data[i];
        }

        return res;
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) return "";

        string currEncode = "";
        vector<pair<string, int>> store;

        preorder(root, currEncode, store);

        string encode = to_string(root->val) + "|";

        for (int i = 1; i < store.size(); ++i) {
            encode += store[i].first + to_string(store[i].second) + "|";
        }

        return encode;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "") return nullptr;

        vector<pair<string, int>> decode = decodeString(data);

        TreeNode* root = new TreeNode(decode[0].second);

        for (int i = 1; i < decode.size(); ++i) {
            buildTree(root, decode[i].first, decode[i].second);
        }

        return root;
    }
};
