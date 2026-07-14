class Solution {
public:
    int findMin(vector<int> &nums) {
        // Binary Search solution
        if (nums.size() == 1) return nums[0];
        else if (nums.size() == 2) return nums[0] > nums[1] ? nums[1] : nums[0];

        int l = 0, r = nums.size() - 1, ans = nums[0];

        while (l <= r) {
            if (nums[l] < nums[r]) {
                ans = min(ans, nums[l]);
                break;
            }
            int mid = l + (r - l) / 2;
            ans = min(ans, nums[mid]);

            if (nums[mid] >= nums[l]) l = mid + 1;
            else r = mid - 1;
        }

        return ans;
    }
};
