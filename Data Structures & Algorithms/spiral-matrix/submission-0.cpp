class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int N = matrix.size(), M = matrix[0].size();

        int left = 0, right = M - 1, top = 0, bottom = N - 1;


        while (left <= right && top <= bottom) {
            // TOP BORDER
            for (int i = left; i <= right; ++i) {
                res.push_back(matrix[top][i]);
            }

            // RIGHT BORDER
            for (int i = top + 1; i <= bottom; ++i) {
                res.push_back(matrix[i][right]);
            }

            // BOTTOM BORDER
            for (int i = right - 1; i >= left && top != bottom; --i) {
                res.push_back(matrix[bottom][i]);
            }

            // LEFT BORDER
            for (int i = bottom - 1; i >= top + 1 && left != right; --i) {
                res.push_back(matrix[i][left]);
            }

            left++;
            top++;
            right--;
            bottom--;
        }

        return res;
    }
};
