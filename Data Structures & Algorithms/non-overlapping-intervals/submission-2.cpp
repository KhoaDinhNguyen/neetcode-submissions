class Solution {
public:
    /**
    The idea is that we only care about the end, and for greedy, we want to take the ntervals that end first
    **/
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        int prevEnd = intervals[0][1];
        int ans = 0;

        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] < prevEnd) {
                prevEnd = min(prevEnd, intervals[i][1]);
                ans++;
            }
            else {
                prevEnd = intervals[i][1];
            }
        }

        return ans;
    }
};
