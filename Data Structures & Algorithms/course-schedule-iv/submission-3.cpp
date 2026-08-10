class Solution {
public:
    unordered_map<int, unordered_set<int>> mp;
    vector<vector<int>> adjList;

    void dfs(int index) {
        if (mp.count(index)) return;

        unordered_set<int> nextCourses;
        
        for (int i = 0; i < adjList[index].size(); ++i) {
            int nextIdx = adjList[index][i];
            dfs(nextIdx);
            nextCourses.insert(mp[nextIdx].begin(), mp[nextIdx].end());
        }
        
        nextCourses.insert(index);

        mp[index] = nextCourses;
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        // Build adjency list
        adjList = vector<vector<int>>(numCourses);

        for (int i = 0; i < prerequisites.size(); ++i) {
            adjList[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        // Call dfs
        for (int i = 0; i < numCourses; ++i) {
            if (mp.count(i) == 0) {
                dfs(i);
            }
        }

        vector<bool> ans(queries.size());

        for (int i = 0; i < queries.size(); ++i) {
            ans[i] = mp[queries[i][0]].count(queries[i][1]);
        }

        return ans;
    }
};
