class Solution {
public:
    vector<vector<int>> dp;
    int dfs(int r, int c, int n, int m, vector<vector<char>>& matrix) {
        if (r >= n || c >= m) return 0;
        if (dp[r][c] != -1) return dp[r][c];

        int down = dfs(r + 1, c, n, m, matrix);
        int right = dfs(r, c + 1, n, m, matrix);
        int diag = dfs(r + 1, c + 1, n, m, matrix);

        dp[r][c] = 0;

        if (matrix[r][c] == '1') {
            dp[r][c] = 1 + min(down, min(right, diag));
        }

        return dp[r][c];
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        int N = matrix.size(), M = matrix[0].size();

        dp = vector<vector<int>>(N, vector<int>(M, -1));

        int maxSquare = 0;

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                maxSquare = max(maxSquare, dfs(i, j, N, M, matrix));
            }
        }    

        return maxSquare * maxSquare;
    }
};