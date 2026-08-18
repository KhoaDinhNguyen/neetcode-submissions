class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> prices(n, INT_MAX);
        prices[src] = 0;

        for (int i = 0; i <= k; ++i) {
            vector<int> tmpPrices = prices;

            for (const auto& flight: flights) {
                int u = flight[0], v = flight[1], w = flight[2];

                if (prices[u] != INT_MAX && tmpPrices[v] > prices[u] + w) {
                    tmpPrices[v] = prices[u] + w;
                }
            }

            prices = tmpPrices;
        }

        return prices[dst] == INT_MAX? -1: prices[dst];
    }
};
