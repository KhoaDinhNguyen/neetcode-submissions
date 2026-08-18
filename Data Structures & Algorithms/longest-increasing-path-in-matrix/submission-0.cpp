class Solution {
public:
    vector<vector<int>> dp;
    int dfs(int r, int c, vector<vector<int>>& matrix, int prevVal) {
        int N = matrix.size(), M = matrix[0].size();
        
        if (r < 0 || r >= N || c < 0 || c >= M || matrix[r][c] <= prevVal) return 0;
        if (dp[r][c] != -1) return dp[r][c];

        int res = 1;
        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        for (const auto& dir: directions) {
            res = max(res, 1 + dfs(r + dir[0], c + dir[1], matrix, matrix[r][c]));
        }

        return dp[r][c] = res;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int N = matrix.size(), M = matrix[0].size();
    
        dp = vector<vector<int>>(N, vector<int>(M, -1));
        int ans = 0;

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                ans = max(ans, dfs(i, j, matrix, INT_MIN));
            }
            cout << endl;
        }

        return ans;

    }
};
