class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        /**
        1 2 3
        4 5 6
        7 8 9

        7 8 9
        4 5 6
        1 2 3
        
        **/

        int N = matrix.size();

        // Reverse vertically
        for (int i = 0; i < N / 2; ++i) {
            for (int j = 0; j < N; ++j) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[N - 1 - i][j];
                matrix[N - 1 - i][j] = temp;
            }
        }

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < i; ++j) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }

    }
};
