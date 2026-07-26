class Solution {
public:
    unordered_set<int> pacific;
    unordered_set<int> atlantic;
    int M = 0;
    void insertIdx(bool isPacific, int r, int c) {
        int idx = r * M + c;

        if (isPacific) pacific.insert(idx);
        else atlantic.insert(idx); 
    }

    bool existIdx(bool isPacific, int r, int c) {
        int idx = r * M + c;

        return isPacific? pacific.find(idx) != pacific.end(): atlantic.find(idx) != atlantic.end();
    }

    /**
    Only visit when the cell heights are greater than current heights
    **/
    void dfs(int r, int c, vector<vector<int>>& heights, bool isPacific) {
        int N = heights.size(), M = heights[0].size();
        int idx = r * M + c;
        int temp = heights[r][c];

        if (existIdx(isPacific, r, c)) return;

        insertIdx(isPacific, r, c);

        heights[r][c] = -1;

        vector<vector<int>> dirs = {{0, 1}, {0, - 1}, {1, 0}, {-1, 0}};

        for (auto dir: dirs) {
            int nextR = r + dir[0], nextC = c + dir[1];

            if (nextR < 0 || nextR >= N || nextC < 0 || nextC >= M || heights[nextR][nextC] == -1) continue;
            if (existIdx(isPacific, nextR, nextC)) continue;
            if (heights[nextR][nextC] < temp) continue;

            dfs(nextR, nextC, heights, isPacific);
        }

        heights[r][c] = temp;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int N = heights.size(), M = heights[0].size();
        this-> M = M;

        // TOP BORDER
        for (int i = 0; i < M; ++i) dfs(0, i, heights, true);

        // LEFT BORDER
        for (int i = 0; i < N; ++i) dfs(i, 0, heights, true);

        // BOTTOM BORDER
        for (int i = 0; i < M; ++i) dfs(N - 1, i, heights, false);

        // RIGHT BORDER
        for (int i = 0; i < N; ++i) dfs(i, M - 1, heights, false);
        
        vector<vector<int>> res;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (existIdx(true, i, j) && existIdx(false, i, j)) {
                   res.push_back({i, j});
                }
            }
        }

        return res;
    }
};
