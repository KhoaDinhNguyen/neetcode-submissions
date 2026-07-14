class Solution {
public:
    int ans = false;
    vector<vector<char>> temp;
    void dfs(int i, int row, int col, set<pair<int, int>>& st, string& word) {
        if (i == word.size()) {
            // cout << i << " " << row << " " << col << endl;
            ans = true;
            return;
        }
        else if (row < 0 || col < 0 || row >= temp.size() || col >= temp[0].size()) return;
        else if (temp[row][col] != word[i]) return;
        else if (st.find({row, col}) != st.end()) return;
        
        pair<int, int> top = {row + 1, col};
        pair<int, int> bottom = {row - 1, col};
        pair<int, int> left = {row, col - 1};
        pair<int, int> right = {row, col + 1};

        st.insert({row , col});
        dfs(i + 1, row - 1, col, st, word);
        dfs(i + 1, row, col - 1, st, word);
        dfs(i + 1, row, col + 1, st, word);
        dfs(i + 1, row + 1, col, st, word);
        st.erase({row, col});
    }
    bool exist(vector<vector<char>>& board, string word) {
        temp = board;
        set<pair<int, int>> st;
        for (int i = 0 ; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                dfs(0, i, j, st, word);
            }
        }

        return ans;
    }
};
