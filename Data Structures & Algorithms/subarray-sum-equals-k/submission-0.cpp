class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int N = nums.size();

        vector<int> prefixSum(N + 1, 0);

        for (int i = 0; i < N; ++i) {
            prefixSum[i + 1] = prefixSum[i] + nums[i]; 
        }

        int ans = 0;

        for (int i = 0; i <= N; ++i) {
            for (int j = i + 1; j <= N; ++j) {
                if (prefixSum[j] - prefixSum[i] == k) {
                    ans++;
                }
            }
        }

        return ans;
    }
};