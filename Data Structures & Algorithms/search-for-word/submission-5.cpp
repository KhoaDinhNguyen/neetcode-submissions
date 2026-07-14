class Solution {
public:
    int ans = false;
    vector<vector<char>> temp;
    void dfs(int i, int row, int col, string& word) {
        if (i == word.size()) {
            ans = true;
            return;
        }
        else if (row < 0 || col < 0 || row >= temp.size() || col >= temp[0].size()) return;
        else if (temp[row][col] != word[i]) return;
        else if (temp[row][col] == '#') return;

        temp[row][col] = '#';
    
        dfs(i + 1, row - 1, col, word);
        dfs(i + 1, row, col - 1, word);
        dfs(i + 1, row, col + 1, word);
        dfs(i + 1, row + 1, col, word);
        
        temp[row][col] = word[i];
    }
    bool exist(vector<vector<char>>& board, string word) {
        temp = board;
        for (int i = 0 ; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                dfs(0, i, j, word);
            }
        }

        return ans;
    }
};
