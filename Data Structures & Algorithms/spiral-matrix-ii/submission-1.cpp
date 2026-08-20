class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int currNum = 1;

        vector<vector<int>> ans(n, vector<int>(n, 0));
        int l = 0, t = 0, b = n, r = n;

        while (currNum <= n * n) {
            // top border
            for (int i = l; i < r; ++i) {
                ans[t][i] = currNum++;
            }

            t++;

            // right border
            for (int i = t; i < b; ++i) {
                ans[i][r - 1] = currNum++;
            }

            r--;

            // bottom border
            for (int i = r - 1; i >= l; --i) {
                ans[b - 1][i] = currNum++;
            }

            b--;
            // left border

            for (int i = b - 1; i >= t; --i) {
                ans[i][l] = currNum++;
            }

            l++;
        }   

        return ans;
    }
};