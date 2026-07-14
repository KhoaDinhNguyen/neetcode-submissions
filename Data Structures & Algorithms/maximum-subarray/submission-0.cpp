class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int N = nums.size();

        int best = -1000, ans = -1000;

        for (int i = 0; i < N; ++i) {
            best = max(best + nums[i], nums[i]);
            ans = max(ans, best);
        }

        return ans;
    }
};
