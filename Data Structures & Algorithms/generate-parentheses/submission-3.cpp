class Solution {
public:
    vector<string> res;

    void dfs(string& subset, int close, int open, int n) {
        if (close + open >= 2 * n) {
            res.push_back(subset);
            return;
        }

        if (open < n) {
            subset.push_back('(');
            dfs(subset, close, open + 1, n);
            subset.pop_back();
        }
        if (close < open) {
            subset.push_back(')');
            dfs(subset, close + 1, open, n);
            subset.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        string subset = "";
        dfs(subset, 0, 0, n);

        return res;    
    }
};
