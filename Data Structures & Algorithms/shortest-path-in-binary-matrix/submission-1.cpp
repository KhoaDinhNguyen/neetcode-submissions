class Solution {
public:
    vector<vector<int>> dp;
    vector<vector<bool>> visited;

    int dfs(int r, int c, int n, int m, vector<vector<int>>& grid) {
        if (r < 0 || r >= n || c < 0 || c >= m) return -1;
    
        if (visited[r][c]) return dp[r][c];

        visited[r][c] = true;

        if (grid[r][c] == 1) return dp[r][c] = -1;
        if (r == n - 1 && c == m - 1) return dp[r][c] = 1;

        int res = 100000;

        vector<vector<int>> directions = {
            {1, 0}, {-1, 0},
            {0, 1}, {0, -1},
            {1, 1}, {-1, 1},
            {1, -1}, {-1, -1}
        };

        for (auto dir : directions) {
            int score = dfs(r + dir[0], c + dir[1], n, m, grid);
            
            if (score != -1) {
                res = min(res, score + 1);
            }
        }

        if (res == 100000) return dp[r][c] = -1;

        return dp[r][c] = res;
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int N = grid.size(), M = grid[0].size();

        if (grid[0][0] != 0 || grid[N - 1][M - 1] != 0) return -1;

        dp = vector<vector<int>>(N, vector<int>(M, -1));

        visited = vector<vector<bool>>(N, vector<bool>(M, false));

        dfs(0, 0, N, M, grid);


        // for (int i = 0; i < N; ++i) {
        //     for (int j = 0; j < N; ++j) {
        //         cout << dp[i][j] << " ";
        //     }

        //     cout << endl;
        // }
        return dp[0][0]; 
    }
};