class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int N = nums.size();

        for (int i = 0; i < N; ++i) {
            int n = abs(nums[i]);

            if (nums[n - 1] > 0) nums[n - 1] *= -1;
        }

        vector<int> res;

        for (int i = 0; i < N; ++i) {
            if (nums[i] > 0) {
                res.push_back(i + 1);
            }
        }

        return res;
    }
};