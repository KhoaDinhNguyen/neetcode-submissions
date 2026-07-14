class Solution {
public:
    vector<vector<bool>> visited;
    vector<vector<char>> temp;
    void dfs(int i, int j) {
        if (i < 0 || i >= temp.size() || j < 0 || j >= temp[0].size()) return;
        if (visited[i][j] == true) return;

        visited[i][j] = true;

        if (temp[i][j] == '1') {
            dfs(i + 1, j);
            dfs(i - 1, j);
            dfs(i, j + 1);
            dfs(i, j - 1);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        temp = grid;
        int N = grid.size(), M = grid[0].size();

        for (int i = 0; i < N; ++i) {
            vector<bool> v(M, false);
            visited.push_back(v);
        }

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (visited[i][j] == false && temp[i][j] == '1') {
                    ans++;
                    dfs(i, j);
                }
            }
        }

        return ans;
    }
};
