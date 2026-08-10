class Solution {
public:
    int rob(vector<int>& nums) {
        int N = nums.size();

        if (N == 1) return nums[0];

        vector<int> robLeft(N, 0);
        vector<int> robRight(N, 0);

        robLeft[0] = 0;
        robLeft[1] = 0;

        for (int i = 2; i < N; ++i) {
            // Choose not to rob at i-th
            robLeft[i] = robLeft[i - 1];

            // Choose to rob at i-th
            robLeft[i] = max(robLeft[i], robLeft[i - 2] + nums[i - 2]);
        }

        robRight[N - 1] = 0;
        robRight[N - 2] = 0;

        for (int i = N - 3; i >= 0; --i) {
            // Choose not to rob at it
            robRight[i] = robRight[i + 1];

            // Choose to rob at i-th
            robRight[i] = max(robRight[i], robRight[i + 2] + nums[i + 2]);
        }

        int ans = 0;

        for (int i = 0; i < N; ++i) {
            ans = max(ans, robLeft[i] + robRight[i] + nums[i]);
        }

        return ans;
    }
};
