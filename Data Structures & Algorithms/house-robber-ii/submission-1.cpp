class Solution {
public:
    int robI(vector<int>& nums) {

        int N = nums.size();
        vector<int> left(N, 0); // left[i] presents maximum rob value before ith
        vector<int> right(N, 0); // right[i] presents maximum rob value after ith
        
        for (int i = 2; i < N; ++i) {
            // Comparing between
            // left[i - 1] -> chose to not rob at ith
            // left[i - 2] -> chose to rob at ith
            left[i] = max(left[i - 1], left[i - 2] + nums[i - 2]);
            right[N - 1 - i] = max(right[N - i], right[N - i + 1] + nums[N - i + 1]);
        }

        int res = 0;

        for (int i = 0; i < N; ++i) {
            // result is maximum rob value before ith + maximum rob value after ith + rob valu at ith
            res = max(res, left[i] + right[i] + nums[i]);
        }

        return res;

    }

    // using rob fucntion from House Robber I
    // Then robII is max between robbing second to last and first to second-to-last
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        
        int N = nums.size();

        vector<int> round1, round2;

        for (int i = 0; i < N - 1; ++i) {
            round1.push_back(nums[i]);
            round2.push_back(nums[i + 1]);
        }

        return max(robI(round1), robI(round2));
    }
};
