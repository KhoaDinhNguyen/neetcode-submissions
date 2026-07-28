class Solution {
public:
    /**
    The idea is that for each 0, we update the vertical (top) and horizontal (left) value to 0
    1 1 1     1 0 1
    1 0 1 --> 0 0 1 
    1 1 1     1 1 1

    Then after computing, we know that if a row has a zero, then every row is 0, same for column

    Problem: how about the 0 on the borders
    --> Solution: use 2 boolean values to keep it
    **/
    void setZeroes(vector<vector<int>>& matrix) {
        bool top = false, left = false;

        int N = matrix.size(), M = matrix[0].size();

        for (int i = 0; i < N; ++i) {
            if (matrix[i][0] == 0) left = true;
        }

        for (int i = 0; i < M; ++i) {
            if (matrix[0][i] == 0) top = true;
        }

        for (int i = 1; i < N; ++i) {
            for (int j = 1; j < M; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }

        // Update the rows
        for (int i = 1; i < N; ++i) {
            if (matrix[i][0] == 0) {
                for (int j = 0; j < M; ++j) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        // Update the columns
        for (int j = 1; j < M; ++j) {
            if (matrix[0][j] == 0) {
                for (int i = 0; i < N; ++i) {
                    matrix[i][j] = 0;
                }
            }
        }

        if (top) {
            for (int i = 0; i < M; ++i) {
                matrix[0][i] = 0;
            }
        }

        if (left) {
            for (int i = 0; i < N; ++i) {
                matrix[i][0] = 0;
            }
        }

    }

    // Time complexity: O(N * M)
    // Space complexity: O(1)
};
