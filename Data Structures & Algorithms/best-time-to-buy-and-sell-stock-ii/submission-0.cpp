class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 1) return 0;

        int buy = -prices[0], sell = 0, ans = 0;

        for (int i = 1; i < prices.size(); ++i) {
            buy = max(buy, sell - prices[i]);
            sell = max(sell, buy + prices[i]);
        }

        return sell;
    }
};