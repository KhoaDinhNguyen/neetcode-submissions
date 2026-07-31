class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int N = nums.size(), sum = 0;

        for (auto num: nums) {
            sum += num;
        }

        if (sum % 2 == 1) return false;

        vector<vector<bool>> dp(N + 1, vector<bool>(sum / 2 + 1, 0));

        for (int i = 0; i <= N; ++i) {
            dp[i][0] = true;
        }

        for (int i = 1; i <= N; ++i) {
            for (int amount = 1; amount <= sum / 2; ++amount) {
                dp[i][amount] = dp[i - 1][amount];

                if (amount >= nums[i - 1]) {
                    dp[i][amount] = dp[i - 1][amount - nums[i - 1]] || dp[i][amount];
                }
            }
        }

        return dp[N][sum / 2];
    }
};
