class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int N = intervals.size();

        vector<vector<int>> ans;
        
        int i = 0;

        // first push interval that have end < the start of new interval
        while (i < N && intervals[i][1] < newInterval[0]) {
           ans.push_back(intervals[i]);
           i++;
        }

        // For then next interval, start merging
        while (i < N && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }

        ans.push_back(newInterval);
        // For the remaining intervals, push into the output

        while (i < N) {
            ans.push_back(intervals[i]);
            i++;
        }

        return ans;
    }
};
