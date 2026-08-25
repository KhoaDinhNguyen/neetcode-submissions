class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, r = 0, N = nums.size();

        int ans = INT_MAX, currSum = 0;

        while (r < N) {
            if (currSum < target) {
                currSum += nums[r];
                r++;
            }      

            while (currSum >= target && l < r) {   
                ans = min(ans, r - l);
                currSum -= nums[l];
                l++;
            }
        }

        return ans == INT_MAX? 0: ans;
    }
};