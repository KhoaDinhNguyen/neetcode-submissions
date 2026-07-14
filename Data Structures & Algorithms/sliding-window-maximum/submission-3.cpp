class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int N = nums.size();

        vector<int> leftMax(N, 0), rightMax(N, 0);

        leftMax[0] = nums[0];
        rightMax[N - 1] = nums[N - 1];

        for (int i = 1; i < N; ++i) {
            if (i % k == 0) {
                leftMax[i] = nums[i];
            }
            else {
                leftMax[i] = max(leftMax[i - 1], nums[i]);
            }

            if ((N - 1 - i) % k == 0) {
                rightMax[N - 1 - i] = nums[N - 1 - i];
            }
            else {
                rightMax[N - 1 - i] = max(rightMax[N - i], nums[N - 1 - i]);
            }
        }

        vector<int> ans;

        for (int i = 0; i < N - k + 1; ++i) {
            ans.push_back(max(rightMax[i], leftMax[i + k - 1]));
        }

        return ans;
    }
};
