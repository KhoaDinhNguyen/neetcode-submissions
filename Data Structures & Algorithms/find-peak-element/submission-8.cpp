class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        else if (nums[0] > nums[1]) return 0;
        else if (nums[nums.size() - 1] > nums[nums.size() - 2]) return nums.size() - 1;

        int l = 0, r = nums.size();

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) {
                return mid;
            }
            else if (nums[mid] < nums[mid - 1]) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }

        return -1;
    }
};