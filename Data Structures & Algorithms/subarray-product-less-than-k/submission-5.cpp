class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int N = nums.size();

        int res = 0, l = 0;
        long long product = 1;

        for (int r = 0; r < N; ++r) {
            product *= nums[r];

            while (l <= r && product >= k) {
                product = product / nums[l++];
            }

            res += (r - l + 1); 
        }

        return res;
    }
};