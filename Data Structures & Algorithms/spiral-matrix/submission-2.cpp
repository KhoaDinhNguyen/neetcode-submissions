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
            top++;

            // RIGHT BORDER
            for (int i = top; i <= bottom; ++i) {
                res.push_back(matrix[i][right]);
            }
            right--;

            // If the remaining rectangle is invalid, break (prevents duplicates).
            if (!(left <= right && top <= bottom)) break;

            // BOTTOM BORDER
            for (int i = right; i >= left; --i) {
                res.push_back(matrix[bottom][i]);
            }
            bottom--;

            // LEFT BORDER
            for (int i = bottom; i >= top; --i) {
                res.push_back(matrix[i][left]);
            }
            left++;
        }

        return res;
    }

    // Time Complexity: O(M * N)
    // Space complexity: O(1)
};
