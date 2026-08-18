class Solution {
public:
    vector<vector<int>> dp;
    
    int dfs(int l, int r, vector<int>& nums) {
        if (l > r) return 0;
        if (dp[l][r] != -1) return dp[l][r];

        dp[l][r] = 0;

        for (int i = l; i <= r; ++i) {
            int res = nums[l - 1] * nums[i] * nums[r + 1];
            res += dfs(l, i - 1, nums) + dfs(i + 1, r, nums);

            dp[l][r] = max(res, dp[l][r]);
        }

        return dp[l][r];
    }

    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        int N = nums.size();

        dp = vector<vector<int>>(N, vector<int>(N, -1));

        return dfs(1, N - 2, nums);
    }
};
