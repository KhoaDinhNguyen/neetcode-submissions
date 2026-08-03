class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int N = boxGrid.size(), M = boxGrid[0].size();

        vector<vector<char>> res(M, vector<char>(N, '.'));

        for (int i = 0; i < N; ++i) {
            int k = M - 1;

            for (int j = M - 1; j >= 0; --j) {
                if (boxGrid[i][j] == '#') {
                    swap(boxGrid[i][j], boxGrid[i][k]);
                    k--;
                }
                else if (boxGrid[i][j] == '*') {
                    k = j - 1;
                }
            }    
        }

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                res[j][N - 1 - i] = boxGrid[i][j];
            }
        }

        return res;
    }
};