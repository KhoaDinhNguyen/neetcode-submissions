class Solution {
public:
    int robI(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];

        vector<int> dp(nums.size(), -1);

        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < nums.size(); ++i) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }

        return dp[nums.size() - 1];
    }
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];

        vector<int> oneToNMius1 = nums;
        oneToNMius1.pop_back();

        vector<int> twoToN = nums;
        twoToN.erase(twoToN.begin());

        return max(robI(oneToNMius1), robI(twoToN));
    }
};
