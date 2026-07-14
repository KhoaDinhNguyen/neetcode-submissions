class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int N = grid.size(), M = grid[0].size();
        
        int ans = 0, fresh = 0;

        // Preprosessing
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (grid[i][j] == 1) fresh++;
                else if (grid[i][j] == 2) q.push({i, j});
            }
        }

        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

        while (!q.empty()) {
            int k = q.size();
       
            for (int i = 0; i < k; ++i) {
                int r = q.front().first, c = q.front().second;
                q.pop();

                for(auto dir: directions) {
                    int row = r + dir.first;
                    int col = c + dir.second;

                    if (row < 0 || col < 0 || row >= N || col >= M) continue;
                    if (grid[row][col] == 2 || grid[row][col] == 0) continue;

                    q.push({row, col});
                    grid[row][col] = 2;
                    fresh--;
                }
            }

            if (!q.empty()) ans++;
        }


        return fresh == 0? ans: -1;
    }
};
