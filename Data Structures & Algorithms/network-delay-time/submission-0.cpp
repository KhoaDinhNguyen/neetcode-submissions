class Solution {
public:
    // disjktra
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<vector<int>>> adjList(n + 1);

        for (int i = 0; i < times.size(); ++i) {
            int src = times[i][0], dst = times[i][1], cost = times[i][2];

            adjList[src].push_back({cost, dst});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        vector<bool> visited(n + 1);
        vector<int> shortestDist(n + 1, INT_MAX);

        shortestDist[k] = 0;
        minHeap.push({0, k});

        while (!minHeap.empty()) {
            int src = minHeap.top().second;
            minHeap.pop();

            if (visited[src]) continue;

            visited[src] = true;

            for (int i = 0; i < adjList[src].size(); ++i) {
                int dst = adjList[src][i][1], cost = adjList[src][i][0];

                if (cost + shortestDist[src] < shortestDist[dst]) {
                    shortestDist[dst] = cost + shortestDist[src];
                    minHeap.push({cost + shortestDist[src], dst});
                }
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (shortestDist[i] == INT_MAX) return -1;
            ans = max(ans, shortestDist[i]);
        }

        return ans;
    }
};
