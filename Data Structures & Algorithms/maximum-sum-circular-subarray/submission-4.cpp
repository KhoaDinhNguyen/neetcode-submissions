class Solution {
public:
    int maxSubarray(vector<int>& nums) {
        int best = nums[0], ans = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            best = max(nums[i], best + nums[i]);
            ans = max(ans, best);
        }

        return ans;
    }
    int minSubarray(vector<int>& nums) {
        int worse = nums[0], ans = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            worse = min(nums[i], worse + nums[i]);
            ans = min(ans, worse);
        }

        return ans;
    }

    int maxSubarraySumCircular(vector<int>& nums) {
        int total = 0;

        for (int i = 0; i < nums.size(); ++i) {
            total += nums[i];
        }

        int maxSum = maxSubarray(nums);
        int minSum = minSubarray(nums);


        // If the maxSum is negative, return it to avoid select empty array because minSum == total
        if (maxSum < 0) {
            return maxSum;
        }
        return max(maxSum, total - minSum);
    }
};