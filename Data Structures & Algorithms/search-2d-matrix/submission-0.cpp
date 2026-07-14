class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0, r = matrix.size() - 1, mid = 0, M = matrix[0].size();

        while (l <= r) {
            mid = l + (r - l) / 2;

            if (matrix[mid][0] <= target && target <= matrix[mid][M - 1]) break;
            else if (matrix[mid][0] > target) r = mid - 1;
            else l = mid + 1;
        }

        l = 0, r = M - 1;

        while (l <= r) {
            int next_mid = l + (r - l) / 2;
            if(matrix[mid][next_mid] == target) return true;
            else if (matrix[mid][next_mid] > target) r = next_mid - 1;
            else l = next_mid + 1;
        }

        return false;
    }
};
