class Solution {
public:
    int numSquares(int n) {
        vector<int> dp;

        for (int i = 1; i * i <= n; ++i) {
            dp.push_back(i * i);
        }

        // coin change

        vector<int> amount(n + 1, INT_MAX);

        amount[0] = 0;

        for (int i = 0; i < dp.size(); ++i) {
            for (int j = 1; j <= n; ++j) {
                if (j >= dp[i]) {
                    amount[j] = min(amount[j], amount[j - dp[i]] + 1);
                }        
            }
        }

        return amount[n];
    }
};