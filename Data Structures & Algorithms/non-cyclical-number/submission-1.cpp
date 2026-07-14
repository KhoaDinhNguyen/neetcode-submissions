class Solution {
public:
    int cal(int n) {
        int res = 0;

        while (n > 0) {
            res = res + (n % 10) * (n % 10);
            n = n / 10;
        }

        return res;
    }

    bool isHappy(int n) {
        int slow = n, fast = cal(n);

        while (slow != fast){
            fast = cal(fast);
            fast = cal(fast);
            slow = cal(slow);
        }

        return fast == 1;
    }
};
