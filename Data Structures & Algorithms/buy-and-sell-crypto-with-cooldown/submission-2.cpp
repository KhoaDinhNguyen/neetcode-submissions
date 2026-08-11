class Solution {
public:
    int ans = 0;
    vector<vector<int>> dp;
    int dfs(int i, int currentBuy, vector<int>& prices) {
        if (i >= prices.size()) return 0;
        if (dp[currentBuy][i] != -1) return dp[currentBuy][i];

        // If currently you can buy
        if (currentBuy == 0) {
            // Choose to buy at i-th
            dp[0][i] = -prices[i] + dfs(i + 1, 1, prices);

            // Choose not to buy at i-th
            dp[0][i] = max(dp[0][i], dfs(i + 1, 0, prices));
        }
        else {
            // Choose to sell at i-th
            dp[1][i] = prices[i] + dfs(i + 2, 0, prices);

            // Chose not to sell at ith
            dp[1][i] = max(dp[1][i], dfs(i + 1, 1, prices));
        }

        return dp[currentBuy][i];
    }

    int maxProfit(vector<int>& prices) {
        dp = vector<vector<int>>(2, vector<int>(prices.size(), -1));

        dfs(0, 0, prices);

        return dp[0][0];    
    }
};
