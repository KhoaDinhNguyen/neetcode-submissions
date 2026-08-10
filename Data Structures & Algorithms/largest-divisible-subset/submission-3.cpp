class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<int> ans;
        int N = nums.size(), max = 0;

        for (int i = N - 1; i >= 0; --i) {
            vector<int> row;            
            row.push_back(nums[i]);

            int prev = nums[i];
            for (int j = i - 1; j >= 0; --j) {
                if (prev % nums[j] == 0) {
                    row.push_back(nums[j]);
                    prev = nums[j];
                }
            }

            if (row.size() > max) {
                max = row.size();
                ans = row;
            }
        }

        return ans;
    }
};