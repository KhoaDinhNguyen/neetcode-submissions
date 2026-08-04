class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> minQ, maxQ;

        int l = 0;
        int ans = 0;

        for (int r = 0; r < nums.size(); ++r) {
            while (!minQ.empty() && nums[r] < minQ.back()) {
                minQ.pop_back();
            }
            while (!maxQ.empty() && nums[r] > maxQ.back()) {
                maxQ.pop_back();
            }

            minQ.push_back(nums[r]);
            maxQ.push_back(nums[r]);

            while (maxQ.front() - minQ.front() > limit) {
                if (nums[l] == maxQ.front()) {
                    maxQ.pop_front();
                }
                if (nums[l] == minQ.front()) {
                    minQ.pop_front();
                }
                l++;
            }

            ans = max(ans, r - l + 1);
        }

        return ans;
    }

    // Time O(N)
    // Space O(N)
};