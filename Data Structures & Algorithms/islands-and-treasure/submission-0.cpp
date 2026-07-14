class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int N = grid.size(), M = grid[0].size();

        vector<vector<bool>> visited(N, vector<bool>(M, false));

        queue<pair<int, int>> q;

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                    visited[i][j] = true;
                }
            }
        }

        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        int ds = 1;

        while (!q.empty()) {
            int k = q.size();

            for (int i = 0; i < k; ++i) {
                int row = q.front().first, col = q.front().second;
                q.pop();

                for (auto dir: directions) {
                    int r = row + dir.first,  c = col + dir.second;

                    if (r < 0 || r >= N || c < 0 || c >= M) continue;
                    else if (grid[r][c] == 0 || visited[r][c] || grid[r][c] == -1) continue;

                    visited[r][c] = true;
                    q.push({r, c});
                    grid[r][c] = ds;
                }
            }

            ds++;
        }
    }
};
