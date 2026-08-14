class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int N = nums.size();

        vector<long long> prefixSum(N + 1, 0);

        for (int i = 0; i < N; ++i) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }

        for (int i = 0; i <= N; ++i) {
            for (int j = i + 2; j <= N; ++j) {
                if ((prefixSum[j] - prefixSum[i]) % k == 0) return true;
            }
        }

        return false;
    }
};