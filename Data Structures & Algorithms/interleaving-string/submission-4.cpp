class Solution {
public:
    vector<vector<int>> dp;

    bool dfs(int i, int j, string& s1, string& s2, string& s3) {
        if (i + j == s3.size()) return (i == s1.size()) && (j == s2.size());
        if (dp[i][j] != -1) return dp[i][j];
      
        bool res = false;

        if (i < s1.size() && s3[i + j] == s1[i]) {
            res = dfs(i + 1, j, s1, s2, s3);
        }
        if (!res && j < s2.size() && s3[i + j] == s2[j]) {
            res = dfs(i, j + 1, s1, s2, s3);
        }

        return dp[i][j] = res;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if (s3.size() != s1.size() + s2.size()) return false; 

        int N = s1.size(), M = s2.size();

        dp = vector<vector<int>>(N + 1, vector<int>(M + 1, -1));

        dfs(0, 0, s1, s2, s3);

        return dp[0][0];
    }

    // Time O(N * M)
    // Space O(M * N)
};
