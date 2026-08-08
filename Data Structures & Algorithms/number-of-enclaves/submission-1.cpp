class Solution {
public:
    vector<vector<bool>> visited;
    vector<vector<bool>> boundary;
    
    int dfs(int r, int c, int n, int m, vector<vector<int>>& grid) {
        if (r < 0 || r >= n || c < 0 || c >= m) return 0;
        if (grid[r][c] == 0) return 0;
        if (visited[r][c]) return 0;

        visited[r][c] = true;
        int res = 1;

        res = res + dfs(r + 1, c, n, m, grid);
        res = res + dfs(r - 1, c, n, m, grid);
        res = res + dfs(r, c + 1, n, m, grid);
        res = res + dfs(r, c - 1, n, m, grid);

        return res;
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int N = grid.size(), M = grid[0].size();

        visited = vector<vector<bool>>(N, vector<bool>(M, false));

        int land = 0, borderLand = 0;


        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                land += grid[i][j];
                if (grid[i][j] == 1 &&!visited[i][j] && 
                (i == 0 || j == 0 || i == N - 1 || j == M - 1)) {
                    borderLand += dfs(i, j, N, M, grid);
                }
            }
        }

        return land - borderLand;
    }
};