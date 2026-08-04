class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        priority_queue<pair<int,int>> maxHeap;
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        >   minHeap;

        int l = 0;
        int ans = 0;

        for (int r = 0; r < nums.size(); ++r) {
            maxHeap.push({nums[r], r});
            minHeap.push({nums[r], r});

            if (maxHeap.top().first - minHeap.top().first <= limit) {
                ans = max(ans, r - l + 1);
            }
            else {
                while (maxHeap.top().first - minHeap.top().first > limit) {
                    l++;
                    while (!maxHeap.empty() && maxHeap.top().second < l) maxHeap.pop();
                    while (!minHeap.empty() && minHeap.top().second < l) minHeap.pop();
                    
                }
                
            }
        }

        return ans;
    }
};