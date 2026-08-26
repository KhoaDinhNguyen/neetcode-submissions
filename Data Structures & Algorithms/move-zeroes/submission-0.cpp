class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l = 0; // current 0 position
        int r = 0;
        int N = nums.size();

        while (r < N) {
            if (nums[r] != 0) swap(nums[l++], nums[r]);
            r++;
        }
    }
};