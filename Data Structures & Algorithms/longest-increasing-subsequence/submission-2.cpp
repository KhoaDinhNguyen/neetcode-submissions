class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res;
        int ans = 1, N = nums.size();

        res.push_back(nums[0]);

        for (int i = 1; i < N; ++i) {
            int M = res.size();

            if (nums[i] > res[M - 1]) {
                res.push_back(nums[i]);
                ans++;
            }
            else {
                int idx = lower_bound(res.begin(), res.end(), nums[i]) - res.begin();

                res[idx] = nums[i];
            }
        }

        return ans;
    }
};
