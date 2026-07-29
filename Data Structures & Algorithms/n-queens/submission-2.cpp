class Solution {
public:
    /**
    Everytime place the queen, check if the board is valid 
    Backtrack
    **/
    vector<vector<string>> res;
    unordered_set<int> col;
    unordered_set<int> posDia;
    unordered_set<int> negDia;

    bool checkIfTheBoardIsValid(int i, int j) {
        bool colValid = col.find(j) == col.end();
        bool posDiaValid = posDia.find(i + j) == posDia.end();
        bool negDiaValid = negDia.find(i - j) == negDia.end(); 
        
        return colValid && posDiaValid && negDiaValid;
    }

    void dfs(vector<string>& board, int idx) {
        int N = board.size();

        if (idx == N) {
            res.push_back(board);
            return;
        }


        for (int i = 0; i < N; ++i) {
            if (!checkIfTheBoardIsValid(idx, i)) continue;

            board[idx][i] = 'Q';
            col.insert(i);
            posDia.insert(idx + i);
            negDia.insert(idx - i);

            dfs(board, idx + 1);
            
            board[idx][i] = '.';
            col.erase(i);
            posDia.erase(idx + i);
            negDia.erase(idx - i);
        }

        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));

        dfs(board, 0);

        return res;
    }

    // Time Complexity: (N^3*N!)
    // Splace complexity: O(N^2)
};
