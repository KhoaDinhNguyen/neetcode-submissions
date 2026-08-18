class Solution {
public:
    unordered_map<int, int> res;
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        auto cmp = [](vector<int>& i, vector<int>& j) {
            return i[1] - i[0] > j[1] - j[0];
        };

        vector<int> temp = queries;

        sort(intervals.begin(), intervals.end());
        sort(queries.begin(), queries.end());

        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> minHeap;
        int i = 0, j = 0;
        int N = intervals.size(), M = queries.size();

        while (j < M) {
            while (!minHeap.empty() && minHeap.top()[1] < queries[j]) {
                minHeap.pop();
            }

            while (i < N) {
                int start = intervals[i][0], end = intervals[i][1];
                if (queries[j] > end) {
                    i++;
                    continue;
                }
                else if (start <= queries[j] && queries[j] <= end) {
                    minHeap.push({start, end});
                    i++;
                }
                else {
                    break;
                }
            }

            if (minHeap.empty()) res[queries[j]] = -1;
            else res[queries[j]] = minHeap.top()[1] - minHeap.top()[0] + 1;
            j++;
        }

        vector<int> ans(M);

        for (int i = 0; i < M; ++i) ans[i] = res[temp[i]]; 

        return ans;

    }
};
