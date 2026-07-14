class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int N = cost.size();
        int total = 0;

        if (N == 1 || N == 0) return total;

        int costPre1Step = 0, costPre2Step = 0;

        for (int i = 2; i <= N; ++i) {
            total = min(costPre1Step + cost[i - 1], costPre2Step + cost[i - 2]);
            costPre2Step = costPre1Step;
            costPre1Step = total;
        }

        return total;
    }
};
