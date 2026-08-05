class Solution {
public:
    int dfs(vector<vector<int>>& dp, int r, int c, int m, int n)  {
        if (r < 0 || r >= m || c < 0 || c >= n) return 0;
        if (dp[r][c] != -1) return dp[r][c];

        dp[r][c] = dfs(dp, r + 1, c, m, n) + dfs(dp, r, c + 1, m, n);

        return dp[r][c];
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));

        dp[m - 1][n - 1] = 1;
        
        dfs(dp, 0, 0, m, n);

        return dp[0][0]; 
    }
};
