class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int N = coins.size();

        vector<int> dp(amount + 1, 100000);

        dp[0] = 0;

        for (int i = 1; i <= amount; ++i) {
            for (int j = 0; j < N; ++j) {
                if (coins[j] == i) {
                    dp[i] = 1;
                }
                else if (i > coins[j]) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + dp[coins[j]]);
                }
            }
        }

        return dp[amount] == 100000? -1: dp[amount];
    }
};
