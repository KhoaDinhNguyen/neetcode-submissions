class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int N = nums.size();

        unordered_map<int, int> prefixSum;
        int currSum = 0;
        int ans = 0;

        prefixSum[0] = 1;
        
        for (int i = 0; i < N; ++i) {
            currSum += nums[i];

            int diff = currSum - k;

            ans += prefixSum[diff];

            prefixSum[currSum]++;
        }

        return ans;
    }
};