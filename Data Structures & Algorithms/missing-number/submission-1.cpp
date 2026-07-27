class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int N = nums.size(), res = N;

        for (int i = 0; i < N; ++i) {
            res ^= (i ^ nums[i]);
        }

        return res;
    }
};
