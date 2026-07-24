class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int currMin = 1, currMax = 1, res = 0;

        for (int i = 0; i < nums.size(); ++i) {
            int temp = currMax * nums[i];
            currMax = max(max(currMax * nums[i], currMin * nums[i]), nums[i]);
            currMin = min(min(temp, currMin * nums[i]), nums[i]);
            res = max(res, currMax);
        }

        return res;
    }
};
