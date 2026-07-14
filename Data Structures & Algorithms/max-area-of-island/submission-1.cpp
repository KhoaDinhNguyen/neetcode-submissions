class Solution {
public:
    int ans = 0;
    vector<vector<int>> temp;
    int currArea = 0;
    void dfs(int i, int j) {
        if (i < 0 || i >= temp.size() || j < 0 || j >= temp[0].size()) return;
        else if (temp[i][j] == 0) return;

        currArea++;
        ans = max(ans, currArea);
        temp[i][j] = 0;

        dfs(i + 1, j);
        dfs(i - 1, j);
        dfs(i, j + 1);
        dfs(i, j - 1);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        temp = grid;

        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    currArea = 0;
                    dfs(i, j);
                }
            }
        }    

        return ans;
    }
};
