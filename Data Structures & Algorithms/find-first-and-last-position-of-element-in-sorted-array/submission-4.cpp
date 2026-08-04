class Solution {
public:
    int binarySearch(vector<int>& nums, int target, bool leftBias) {
        int i = -1, l = 0, r = nums.size() - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                i = mid;
                if (leftBias) r = mid - 1;
                else l = mid + 1;
            }
            else if (nums[mid] > target) r = mid - 1;
            else l = mid + 1;
        }

        return i;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = binarySearch(nums, target, true);
        int right = binarySearch(nums, target, false);
        return {left, right};
    }
};