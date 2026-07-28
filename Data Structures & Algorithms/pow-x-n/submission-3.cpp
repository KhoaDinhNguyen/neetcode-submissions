class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;
        if (x == 0) return 0;

        // for example n = 10
        // 10 = 1010
        // 10 = x ^ 8 * x ^ 2
        double res = 1;
        long power = abs((long)n);

        while (power) {
            if (power & 1) {
                res = res * x;
            }
            x = x * x;
            power = power >> 1;
        }

        return n > 0? res: 1 / res;
    }
};
