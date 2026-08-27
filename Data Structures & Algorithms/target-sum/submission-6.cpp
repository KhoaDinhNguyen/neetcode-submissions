class Solution {
public:
    int ans = 0;
    int total = 0;
    vector<vector<int>> dp;
    int dfs(int i, int currSum, int target, vector<int>& nums) {
        if (i == nums.size()) {
            return currSum == target;
        }
        if (dp[total + currSum][i] != -1) return dp[total + currSum][i];

        int op1 = dfs(i + 1, currSum + nums[i], target, nums);
        int op2 = dfs(i + 1, currSum - nums[i], target, nums);

        return dp[total + currSum][i] = op1 + op2;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); ++i) total += nums[i];

        dp = vector<vector<int>>(total * 2 + 1, vector<int>(nums.size(), -1));

        return dfs(0, 0, target, nums);
    }
};
