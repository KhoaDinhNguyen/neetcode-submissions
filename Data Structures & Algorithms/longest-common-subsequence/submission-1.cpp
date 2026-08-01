class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int N = text1.size(), M = text2.size();
        vector<vector<int>> dp(M + 1, vector<int>(N + 1, 0));

        for (int i = 1; i <= M; ++i) {
            for (int j = 1; j <= N; ++j) {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);

                if (text1[j - 1] == text2[i - 1]) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
                }
            }
        }

        return dp[M][N];        
    }
};
