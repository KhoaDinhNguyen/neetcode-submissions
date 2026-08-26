class Solution {
public:
    vector<vector<bool>> visited;

    void dfs(int r, int c, int n, int m, vector<vector<char>>& board) {
        if (r < 0 || r >= n || c >= m || c < 0) return;
        if (visited[r][c] || board[r][c] == 'X') return;

        visited[r][c] = true;

        dfs(r + 1, c, n, m, board);
        dfs(r - 1, c, n, m, board);
        dfs(r, c + 1, n, m, board);
        dfs(r, c - 1, n, m, board);
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        visited = vector<vector<bool>>(n, vector<bool>(m, false));

        for (int i = 0; i < m; ++i) {
            if (board[0][i] == 'O') dfs(0, i, n, m, board);
            if (board[n - 1][i] == 'O') dfs(n - 1, i, n, m, board);
        }    

        for (int i = 0; i < n; ++i) {
            if (board[i][0] == 'O') dfs(i, 0, n, m, board);
            if (board[i][m - 1] == 'O') dfs(i, m - 1, n, m, board);
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] == 'X') continue;
                if (visited[i][j] == true) continue;

                board[i][j] = 'X';
            }
        }
    }
};
