class Solution {
public:
    unordered_map<int, int> res;
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        auto cmp = [](vector<int>& i, vector<int>& j) {
            return i[1] - i[0] > j[1] - j[0];
        };

        vector<int> sortedQuries = queries;

        sort(intervals.begin(), intervals.end());
        sort(sortedQuries.begin(), sortedQuries.end());

        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> minHeap;
        int i = 0, j = 0;
        int N = intervals.size(), M = sortedQuries.size();

        while (j < M) {
            while (i < N && intervals[i][0] <= sortedQuries[j]) {
                int start = intervals[i][0], end = intervals[i][1];
                minHeap.push({start, end});
                i++;
            }

            while (!minHeap.empty() && minHeap.top()[1] < sortedQuries[j]) {
                minHeap.pop();
            }
            if (minHeap.empty()) res[sortedQuries[j]] = -1;
            else res[sortedQuries[j]] = minHeap.top()[1] - minHeap.top()[0] + 1;
            j++;
        }

        vector<int> ans(M);

        for (int i = 0; i < M; ++i) ans[i] = res[queries[i]]; 

        return ans;

    }
};
