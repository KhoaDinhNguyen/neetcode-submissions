class Solution {
public:
    int cal(int n) {
        int ans = 0;

        while (n > 0) {
            ans = ans + n % 2;
            n = n / 2;
        }

        return ans;
    }
    vector<int> countBits(int n) {
        vector<int> ans(n + 1);

        for (int i = 0; i <= n ; ++i) {
            ans[i] = cal(i);
        }

        return ans;
    }
};
