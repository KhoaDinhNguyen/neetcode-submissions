class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;
        if (x == 1) return 1;
        if (n == -1) return 1 / x;
        if (n == 1) return x;

        // If n < 0, return 1 / x^n
        bool negative = n < 0;

        n = abs(n);
    
        // Idea: x ^ 10 = x ^ 8 * x ^2

        int i = 1;
        double temp = x;

        while (true) {
            x = x * x;
            i = i * 2;
            
            if (i == n) {
                return negative? 1.0 / x: x;
            }
            else if (i * 2 > n) {
                int left = n - i;

                while (left > 0) {
                    left--;
                    x = x * temp;
                }

                return negative? 1.0 / x: x;
            }
        }

        return 0;
    }
};
