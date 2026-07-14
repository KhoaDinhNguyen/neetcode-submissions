class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int N = grid.size(), M = grid[0].size();
        
        int ans = 0;

        // Preprosessing
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                    grid[i][j] = -1;
                }
                else if (grid[i][j] == 0) grid[i][j] = -1;
            }
        }

        while (!q.empty()) {
            int k = q.size();
            bool fresh = false;

            for (int i = 0; i < k; ++i) {
                int r = q.front().first, c = q.front().second;
                q.pop();
 
                if (r < N - 1 && grid[r + 1][c] == 1) {
                    q.push({r + 1, c});
                    grid[r + 1][c] = -1;
                    fresh = true;
                }
                if (r > 0 && grid[r - 1][c] == 1) {
                    q.push({r - 1, c});
                    grid[r - 1][c] = -1;
                    fresh = true;
                }
                if (c < M - 1 && grid[r][c + 1] == 1) {
                    q.push({r, c + 1});
                    grid[r][c + 1] = -1;
                    fresh = true;
                }
                if (c > 0 && grid[r][c - 1] == 1) {
                    q.push({r, c - 1});
                    grid[r][c - 1] = -1;
                    fresh = true;
                }
            }

            if (fresh) ans++;
        }

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (grid[i][j] == 1) return -1;
            }
        }

        return ans;
    }
};
