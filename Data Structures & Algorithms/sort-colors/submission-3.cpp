class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0, r = nums.size() - 1, N = nums.size(), i = 0;

        while (i < N) {
            while (l < N && nums[l] == 0) l++;
            while (r >= 0 && nums[r] == 2) r--;
            if (nums[i] == 0 && l < i) swap(nums[i], nums[l++]);
            if (nums[i] == 2 && r > i) swap(nums[i], nums[r--]);
            else i++;
        }
    }
};