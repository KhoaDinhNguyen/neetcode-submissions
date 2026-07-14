class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> heap;

        vector<int> ans;

        for (int i = 0; i < nums.size(); ++i) {
            heap.push({nums[i], i});

            if (i >= k - 1) {
                while (heap.top().second <= i - k) {
                    heap.pop();
                }

                ans.push_back(heap.top().first);
            }
        }

        return ans;

    }
};
