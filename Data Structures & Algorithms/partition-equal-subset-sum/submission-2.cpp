class Solution {
public:
    // Convert problems to exist sum of subsequence = total sum / 2
    bool canPartition(vector<int>& nums) {
        int N = nums.size(), sum = 0;

        for (auto num: nums) {
            sum += num;
        }

        if (sum % 2 == 1) return false;

        int target = sum / 2;
        vector<bool> dp(target + 1, false);

        dp[0] = true;

        for (int i = 0; i < N; ++i) {
            for (int j = target; j >= nums[i]; --j) {
                dp[j] = dp[j] || dp[j - nums[i]];
            }
        }

        return dp[target];
    }
};
