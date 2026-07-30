class Solution {
public:
    bool isPerfectSquare(int num) {
        long long l = 1, r = num;

        while (l <= r) {
            long long m = l + (r - l) / 2;
            long long sq = m * m;

            if (sq > num) {
                r = m - 1;
            }
            else if (sq < num) {
                l = m + 1;
            }
            else {
                return true;
            }
        }

        return false;
    }
};