class Solution {
public:
    int ans;
    vector<int> dp;

    int dfs(int currSum, vector<int>& nums, int target) {
        if (currSum > target) return 0;
        if (currSum == target) return 1;
        if (dp[currSum] != -1) return dp[currSum];

        int res = 0;

        for (int i = 0; i < nums.size(); ++i) {
            res += dfs(currSum + nums[i], nums, target);
        }

        return dp[currSum] = res;
    }
    int combinationSum4(vector<int>& nums, int target) {
        ans = 0;
        dp = vector<int> (target, -1);

        return dfs(0, nums, target);;
    }
};
