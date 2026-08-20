class Solution {
public:
    int findMin(vector<int> &nums) {
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return min(nums[0], nums[1]);
        
        int l = 0, r = nums.size() - 1, ans = nums[0];

        while (l <= r) {
            if (nums[l] < nums[r]) {
                ans = min(ans, nums[l]);
                break;
            }

            int m = (l + r) / 2;

            ans = min(ans, nums[m]);

            if (nums[m] >= nums[l]) l = m + 1;
            else r = m - 1;
        }

        return ans;
    }
};
