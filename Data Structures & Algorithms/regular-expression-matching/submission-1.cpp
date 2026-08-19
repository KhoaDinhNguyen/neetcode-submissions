class Solution {
public:
    vector<vector<int>> dp;

    bool dfs(int i, int j, string& s, string& p) {
        if (i >= s.size() && j >= p.size()) return true;
        if (j >= p.size()) return false;
        if (dp[i][j] != -1) return dp[i][j];

        bool match = i < s.size() && (s[i] == p[j] || p[j] == '.');

        if (j + 1 < p.size() && p[j + 1] == '*') {
            return dp[i][j] = (dfs(i, j + 2, s, p) || (match && dfs(i + 1, j, s, p)));
        }
        else {
            return dp[i][j] = match && dfs(i + 1, j + 1, s, p);
        }

        return dp[i][j];
    }
    bool isMatch(string s, string p) {
        dp = vector<vector<int>>(s.size() + 1, vector<int>(p.size() + 1, -1));
        return dfs(0, 0, s, p);
    }
};
