class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int N = nums.size();

        unordered_map<int, int> remainder;
        remainder[0] = -1;

        int total = 0;

        for (int i = 0; i < N; ++i) {
            total += nums[i];
            int r = total % k;

            if (remainder.count(r) == 0) {
                remainder[r] = i;
            }
            else if (i - remainder[r] > 1) {
                return true;
            }
        }
        return false;
    }
};