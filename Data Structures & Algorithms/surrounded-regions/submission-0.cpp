class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int N = board.size(), M = board[0].size();

        vector<vector<bool>> visited(N, vector<bool>(M, false));

        queue<pair<int, int>> q;

        for (int i = 0; i < N; ++i) {
            if (board[i][0] == 'O') {
                visited[i][0] = true;
                q.push({i, 0});
            }
            if (board[i][M - 1] == 'O') {
                visited[i][M - 1] = true;
                q.push({i, M - 1});
            }
        }

        for (int i = 0; i < M; ++i) {
            if (board[0][i] == 'O') {
                visited[0][i] = true;
                q.push({0, i});
            }
            if (board[N - 1][i] == 'O') {
                visited[N - 1][i] = true;
                q.push({N - 1, i});
            }
        }

        vector<pair<int, int>> directions = {{0 , 1}, {0, -1}, {1, 0}, {-1, 0}};

        while (!q.empty()) {
            pair<int, int> top = q.front();
            q.pop();
            int row = top.first, col = top.second;

            for (auto dir: directions) {
                int r = row + dir.first, c = col + dir.second;

                if (r < 0 || r >= N || c < 0 || c >= M) continue;
                if (visited[r][c] || board[r][c] == 'X') continue;

                visited[r][c] = true;
                q.push({r, c});
            }
        }

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (board[i][j] == 'O' && !visited[i][j]) board[i][j] = 'X';
            }
        }
    }
};
