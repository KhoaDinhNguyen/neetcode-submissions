class Solution {
public:
    int backtrack(int r, int c, vector<vector<int>>& board, vector<vector<int>>& dp) {
        int N = board.size(), M = board[0].size();

        if (r < 0 || r >= N || c < 0 || c >= M) return 0;
        if (dp[r][c] != -1) return dp[r][c];
        if (board[r][c] == 1) return 0;

        dp[r][c] = backtrack(r + 1, c, board, dp) + backtrack(r, c + 1, board, dp);;

        return dp[r][c];
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid[0][0] == 1) return 0;

        int N = obstacleGrid.size(), M = obstacleGrid[0].size();

        vector<vector<int>> dp(N, vector<int>(M, -1));
        dp[N - 1][M - 1] = 1;
        backtrack(0, 0, obstacleGrid, dp);

        return dp[0][0];
    }
};