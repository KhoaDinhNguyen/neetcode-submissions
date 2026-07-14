class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0, minStock = prices[0], N = prices.size();

        for (int i = 1; i < N; ++i) {
            ans = max(ans, prices[i] - minStock);
            minStock = min(minStock, prices[i]);
        }

        return ans;
    }
};
