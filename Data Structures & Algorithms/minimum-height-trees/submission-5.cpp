class Solution {
public:
    int findHeight(vector<vector<int>>& adjList, int idx, vector<int>& visited) {
        visited[idx] = true;
        int height = 0;

        for(int i = 0; i < adjList[idx].size(); ++i) {
            int nextIdx = adjList[idx][i];

            if (!visited[nextIdx]) {
                height = max(height, 1 + findHeight(adjList, nextIdx, visited));        
            }
        }

        visited[idx] = false;

        return height;
    }

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> visited(n, false);
        vector<vector<int>> adjList(n);

        // Create adjList

        for(int i = 0; i < edges.size(); ++i) {
            adjList[edges[i][0]].push_back(edges[i][1]);
            adjList[edges[i][1]].push_back(edges[i][0]);
        }

        // Find height in push into vector
        vector<int> height(n, 0);
        int currMin = INT_MAX;

        for (int i = 0; i < n; ++i) {
            height[i] = findHeight(adjList, i, visited);
            currMin = min(currMin, height[i]);
        }

        vector<int> ans;

        for (int i = 0; i < n; ++i) {
            if (height[i] == currMin) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};