class Solution {
public:
    int reverse(int x) {
        long long ans = 0;
        int sign = x > 0 ? 1: -1;

        x = abs(x);

        while (x > 0) {
            ans = ans * 10 + x % 10;
            x = x / 10;
            if (ans * sign > INT_MAX) return 0;
            if (ans * sign < INT_MIN) return 0;
        }

        return ans * sign;
    }
};
