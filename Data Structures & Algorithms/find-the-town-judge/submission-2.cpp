class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> indegree(n, 0), outdegree(n, 0);

        for (auto t: trust) {
            outdegree[t[0] - 1]++;
            indegree[t[1] - 1]++;
        }

        for (int i = 0; i < n; ++i) {
            if (outdegree[i] == 0 && indegree[i] == n - 1) return i + 1;
        }

        return -1;
    }
};