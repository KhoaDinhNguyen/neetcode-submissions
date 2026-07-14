class Solution {
public:
    vector<vector<int>> twoSum(vector<int>&nums, int start, int end, int target) {
        int i = start, j = end;
        vector<vector<int>> res;

        while (i < j) {
            if (nums[i] + nums[j] > target) j--;
            else if (nums[i] + nums[j] < target) i++;
            else {
                res.push_back({nums[i], -target, nums[j]});
                i++;
                j--;
                while (i < j && nums[i] == nums[i - 1]) i++;
                while (i < j && nums[j] == nums[j + 1]) j--;
            }
        }

        return res;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            vector<vector<int>> res = twoSum(nums, i + 1, nums.size() - 1, 0 - nums[i]);
            for (int k = 0; k < res.size(); ++k) {
                ans.push_back(res[k]);
            }
        }
        return ans;
    }
};
