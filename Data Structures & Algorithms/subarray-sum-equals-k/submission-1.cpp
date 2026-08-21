class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int N = nums.size(), res = 0, currSum = 0;

        unordered_map<int, int> prefixSum;

        prefixSum[0] = 1;

        for (int i = 0; i < N; ++i) {
            currSum += nums[i];
            int diff = currSum - k;

            res += prefixSum[diff];

            prefixSum[currSum]++;
        }

        return res;
    }
};