class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin(), nums.end());
        int N = nums.size();
        int max = 0;

        for (int i = N - 1; i >= 0; --i) {
            vector<int> row;
            row.push_back(nums[i]);

            for (int j = i - 1; j >= 0; --j) {
                if (row[row.size() - 1] % nums[j] == 0) {
                    row.push_back(nums[j]);
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