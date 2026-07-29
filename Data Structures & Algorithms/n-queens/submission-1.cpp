class Solution {
public:
    /**
    Everytime place the queen, check if the board is valid 
    Backtrack
    **/
    vector<vector<string>> res;

    bool checkIfTheBoardIsValid(vector<string>& board, int i, int j) {
        int N = board.size();

        for (int k = 0; k < N; ++k) {
            if (k == j) continue;
            if (board[i][k] == 'Q') return false;
        }

        // Check the column
        for (int k = 0; k < N; ++k) {
            if (k == i) continue;
            if (board[k][j] == 'Q') return false;
        }

        // Check the main diagonal
        int startRow = i - min(i, j), startCol = j - min(i, j);
        for (int k = 0; startRow + k < N && startCol + k < N; ++k) {
            if (startRow + k == i && startCol + k == j) continue;
            if (board[startRow + k][startCol + k] == 'Q') return false;
        }
        
        // Check the other diagonal
        int k = 0;
        while (i + k >= 0 && j - k < N) k--;
        k++;
        while (i + k < N && j - k >= 0) {
            if (k == 0) {
                k++;
                continue;
            }
            if (board[i + k][j - k] == 'Q') return false;
            k++;
        }

        return true;
    }

    void dfs(vector<string>& board, int idx, int n) {
        if (idx == n) {
            res.push_back(board);
            return;
        }


        for (int i = 0; i < n; ++i) {
            if (board[idx][i] == '.') {
                // Place a queen there

                board[idx][i] = 'Q';
                
                if (checkIfTheBoardIsValid(board, idx, i)) {
                    dfs(board, idx + 1, n);
                }
               
                board[idx][i] = '.';
            }
        }

        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));

        dfs(board, 0, n);

        return res;
    }

    // Time Complexity: (N^3*N!)
    // Splace complexity: O(N^2)
};
