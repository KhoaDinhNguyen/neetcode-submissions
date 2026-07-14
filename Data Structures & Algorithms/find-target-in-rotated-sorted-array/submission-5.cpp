class Solution {
public:
    int binarySearchSorted(vector<int>& nums, int i, int j, int target) {
        int l = i, r = j;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] == target) return mid;
            else if (nums[mid] > target) r = mid - 1;
            else l = mid + 1;
        }

        return -1;
    }
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;

        while (l <= r) {
            if (nums[l] < nums[r]) return binarySearchSorted(nums, l, r, target);

            int mid = l + (r - l) / 2;
            if (nums[mid] == target) return mid;
            if (nums[mid] >= nums[l]) {
                if (target > nums[mid]) l = mid + 1;
                else {
                    if (target >= nums[l]) r = mid - 1;
                    else l = mid + 1;
                }
            }
            else {
                if (target < nums[mid]) r = mid - 1;
                else {
                    if (target > nums[r]) r = mid - 1;
                    else l = mid + 1;
                }
            }
        }

        return -1;
    }
};
