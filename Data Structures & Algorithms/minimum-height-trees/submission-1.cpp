class Solution {
public:
    int findHeight(vector<vector<int>>& adjList, int idx, vector<bool>& visited) {
        int height = 0;

        visited[idx] = true;

        for (int i = 0; i < adjList[idx].size(); ++i) {
            int adjNode = adjList[idx][i];

            if (!visited[adjNode]) {
                height = max(height, 1 + findHeight(adjList, adjNode, visited));
            }
        }

        visited[idx] = false;
        
        return height;
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(n);

        for (int i = 0; i < edges.size(); ++i) {
            adjList[edges[i][0]].push_back(edges[i][1]);
            adjList[edges[i][1]].push_back(edges[i][0]);
        };

        vector<bool> visited(n, false);
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

    // Time O(V * (V + E))
    // Space O(V + E)
};