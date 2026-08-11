class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adjList(numCourses, vector<int>());

        for (int i = 0; i < prerequisites.size(); ++i) {
            int mustTake = prerequisites[i][1], thenTake = prerequisites[i][0];

            indegree[thenTake]++;

            adjList[mustTake].push_back(thenTake);
        }

        queue<int> q;

        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int front = q.front();
            q.pop();

            numCourses--;

            for (int i = 0; i < adjList[front].size(); ++i) {
                indegree[adjList[front][i]]--;

                if (indegree[adjList[front][i]] == 0) {
                    q.push(adjList[front][i]);
                }
            }
        }

        return numCourses == 0;
    }
};
