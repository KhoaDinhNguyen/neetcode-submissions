class Solution {
public:
    vector<string> res;

    void dfs(string& subset, int close, int open, int n) {
        if (close + open >= 2 * n) {
            res.push_back(subset);
            return;
        }

        if (open < n) {
            string openString = subset + "(";
            dfs(openString, close, open + 1, n);
        }
        if (close < open) {
            string closeString = subset + ")";
            dfs(closeString, close + 1, open, n);
        }
    }

    vector<string> generateParenthesis(int n) {
        string subset = "";
        dfs(subset, 0, 0, n);

        return res;    
    }
};
