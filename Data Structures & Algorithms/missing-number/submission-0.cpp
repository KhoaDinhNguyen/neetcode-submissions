class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0, N = nums.size();

        for (int i = 0; i < N; ++i) sum += nums[i];

        return (N * (N + 1)) / 2 - sum;
    }
};
