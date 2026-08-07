class Solution {
public:
    vector<vector<int>> dp;
    int totalSum = 0;

    int dfs(int i, vector<int>& nums, int target, int currSum) {
        int N = nums.size();

        if (i == N) return currSum == target;
        if (dp[i][totalSum + currSum] != -1) return dp[i][totalSum + currSum];

        int option1 = dfs(i + 1, nums, target, currSum + nums[i]);
        int option2 = dfs(i + 1, nums, target, currSum - nums[i]);

        return dp[i][totalSum + currSum] = option1 + option2;
        
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); ++i) totalSum += nums[i];
        
        dp = vector<vector<int>>(nums.size(), vector<int>(totalSum * 2 + 1, -1));

        dfs(0, nums, target, 0);

        return dp[0][totalSum];
    }
};
