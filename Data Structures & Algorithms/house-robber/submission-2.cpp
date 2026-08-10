class Solution {
public:
    int rob(vector<int>& nums) {
        int N = nums.size();

        if (N == 1) return nums[0];
        if (N == 0) return 0;

        vector<int> dp(N);

        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < nums.size(); ++i) {
            dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
        }

        return dp[N - 1];
       
    }
};
