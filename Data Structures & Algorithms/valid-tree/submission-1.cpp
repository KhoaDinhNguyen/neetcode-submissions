class Solution {
public:
    vector<vector<int>> adj;

    bool isCycle(int nodeIdx, int preVisit, vector<bool>& visited) {
        if (visited[nodeIdx]) return true;

        visited[nodeIdx] = true;

        vector<int> adjNode = adj[nodeIdx];

        for (int i = 0; i < adjNode.size(); ++i) {
            if (adjNode[i] != preVisit && isCycle(adjNode[i], nodeIdx, visited)) return true;
        }

        return false;

    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<bool> visited(n, false);
        adj.resize(n);

        for (int i = 0; i < edges.size(); ++i) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        if(isCycle(0, -1, visited)) return false;;

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) return false;
        }

        return true;
    }
};
