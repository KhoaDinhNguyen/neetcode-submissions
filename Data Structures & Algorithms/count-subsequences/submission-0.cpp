class Solution {
public:
    vector<vector<int>> dp;

    int dfs(int i, int j, string&s, string& t) {
        if (j == t.size()) return 1;
        else if (i == s.size()) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        if (s[i] == t[j]) {
            return dp[i][j] = dfs(i + 1, j + 1, s, t) + dfs(i + 1, j, s, t);
        }
        
        return dp[i][j] = dfs(i + 1, j, s, t);
    }
    int numDistinct(string s, string t) {
        if (s.size() < t.size() || (s.size() == t.size() && s != t)) return 0;

        dp = vector<vector<int>>(s.size(), vector<int>(t.size(), -1));
        return dfs(0, 0, s, t);
    }
};
