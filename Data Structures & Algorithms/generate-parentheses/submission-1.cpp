class Solution {
public:
    unordered_set<string> resSet;

    void dfs(string& subset, int close, int open, int n) {
        if (close + open >= 2 * n) {
            resSet.insert(subset);
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

        vector<string> res;

        for (auto s: resSet) res.push_back(s);

        return res;    
    }
};
