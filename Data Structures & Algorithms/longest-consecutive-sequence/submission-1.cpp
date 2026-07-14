class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        unordered_set<int> start_nums;
        unordered_set<int> s(nums.begin(), nums.end());

        int N = nums.size();

        for (int i = 0; i < N; ++i) {
            if (s.find(nums[i] - 1) == s.end()) {
                start_nums.insert(nums[i]);
            }
        }

        auto it = start_nums.begin();
        int res = 1;

        while (it != start_nums.end()) {
            int next_start_num = *it + 1, curr = 1;

            while(s.find(next_start_num) != s.end()) {
                curr = curr + 1;
                res = max(res, curr);
                next_start_num++;
            }
            ++it;
        }

        return res;
    }
};
