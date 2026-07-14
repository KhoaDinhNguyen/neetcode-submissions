class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int N = 9;
        int rows[9] = {0}, cols[9] = {0}, boxes[9] = {0};

        for (int r = 0; r < N; ++r) {
            for (int c = 0; c < N; ++c) {
                if (board[r][c] == '.') continue;
                int pos = board[r][c] - '1';
                int val = 1 << pos;

                // check row
                if ((rows[r] & val) > 0) { cout << (rows[r] & val) << " " << r << " " << c; return false;}
                rows[r] = rows[r] | val;

                // check column
                if ((cols[c] & val) > 0) { return false;}
                cols[c] = cols[c] | val;

                // check box
                int idx = (r / 3) * 3 + (c / 3);
                if ((boxes[idx] & val) > 0) return false;
                boxes[idx] = boxes[idx] | val;

            }
        }

        return true;
    }
};
