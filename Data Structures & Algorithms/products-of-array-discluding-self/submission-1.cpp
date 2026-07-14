class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int N = nums.size();
        vector<int> res(N, 1);

        for (int i = N - 2; i >= 0; --i) {
            res[i] = res[i + 1] * nums[i + 1];
        }
        
        int left = 1;

        for (int i = 0; i < N; ++i) {
            res[i] = res[i] * left;
            left = left * nums[i];
        }

        return res;
    }
};
