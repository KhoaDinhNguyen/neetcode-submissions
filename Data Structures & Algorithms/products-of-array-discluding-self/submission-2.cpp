class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int N = nums.size();

        vector<int> leftProduct(N, 1);
        vector<int> rightProduct(N, 1);

        for (int i = 1; i < N; ++i) {
            leftProduct[i] = leftProduct[i - 1] * nums[i - 1];
            rightProduct[N - 1 - i] = rightProduct[N - i] * nums[N - i];
        }

        vector<int> ans(N, 1);

        for (int i = 0; i < N; ++i) {
            ans[i] = leftProduct[i] * rightProduct[i];
        }

        return ans;
    }
};
