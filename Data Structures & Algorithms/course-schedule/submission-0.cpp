class Solution {
public:
    unordered_map<int, vector<int>> adj;

    bool isCycle(int nodeIdx, vector<bool>& visited, vector<bool>& recStack) {
        if (recStack[nodeIdx]) return true;

        if (visited[nodeIdx]) return false;

        visited[nodeIdx] = true;
        recStack[nodeIdx] = true;

        vector<int> adjNode = adj[nodeIdx];

        for (int i = 0; i < adjNode.size(); ++i) {
            if (isCycle(adjNode[i], visited, recStack)) return true;
        }

        recStack[nodeIdx] = false;

        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // detect cycle in the graph
        // adjacency list

        vector<bool> visited(numCourses, false);
        vector<bool> recStack(numCourses, false);

        for (int i = 0; i < prerequisites.size(); ++i) {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        for (int i = 0; i < numCourses; ++i) {
            if (!visited[i] && isCycle(i, visited, recStack)) {
                return false;
            }
        }

        return true;
    }
};
