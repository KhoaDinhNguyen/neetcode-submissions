class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        unordered_set<int> s(nums.begin(), nums.end());

        int N = nums.size();

        int res = 1;

        for (int i = 0; i < N; ++i) {
            if (s.find(nums[i] - 1) == s.end()) {
                int length = 1;
                while (s.find(nums[i] + length) != s.end()) {
                    length++;
                }
                res = max(res, length);
            }

        }

        return res;
    }
};
