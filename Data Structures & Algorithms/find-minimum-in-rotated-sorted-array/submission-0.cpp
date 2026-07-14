class Solution {
public:
    int findMin(vector<int> &nums) {
        if (nums.size() == 1) return nums[0];
        else if (nums.size() == 2) return nums[0] > nums[1] ? nums[1] : nums[0];
        else if (nums[nums.size() - 1] > nums[0]) return nums[0];

        int target = nums[0], l = 0, r = nums.size() - 1;

        while (l < r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] >= target) l = mid + 1;
            else r = mid;
        }

        cout << r << endl;

        return nums[r];
    }
};
