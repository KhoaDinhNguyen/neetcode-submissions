class Solution {
public:
    vector<vector<int>> dp;
    vector<vector<bool>> visited;

    int dfs(int r, int c, int n, vector<vector<int>>& grid) {
        if (r < 0 || r >= n || c < 0 || c >= n) return -1;
    
        if (visited[r][c]) return dp[r][c];

        visited[r][c] = true;

        if (grid[r][c] == 1) return dp[r][c] = -1;
        if (r == n - 1 && c == n - 1) return dp[r][c] = 1;

        int res = 100000;

        vector<vector<int>> directions = {
            {1, 0}, {-1, 0},
            {0, 1}, {0, -1},
            {1, 1}, {-1, 1},
            {1, -1}, {-1, -1}
        };

        for (auto dir : directions) {
            int score = dfs(r + dir[0], c + dir[1], n, grid);
            
            if (score != -1) {
                res = min(res, score + 1);
            }
        }

        if (res == 100000) return dp[r][c] = -1;

        return dp[r][c] = res;
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int N = grid.size();

        if (grid[0][0] != 0 || grid[N - 1][N - 1] != 0) return -1;

        dp = vector<vector<int>>(N, vector<int>(N, -1));

        visited = vector<vector<bool>>(N, vector<bool>(N, false));

        dfs(0, 0, N, grid);

        return dp[0][0]; 
    }
};