class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        else if (n == 2) return 2;

        int prev2Step = 1, prev1Step = 2, currStep = 0;

        while (n > 2) {
            currStep = prev2Step + prev1Step;
            prev2Step = prev1Step;
            prev1Step = currStep;
            n--;
        }

        return currStep;
    }
};
