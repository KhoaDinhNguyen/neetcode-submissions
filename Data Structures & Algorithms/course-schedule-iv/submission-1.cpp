class Solution {
public:
    unordered_map<int, unordered_set<int>> mp;
    unordered_map<int, vector<int>> adjList;

    unordered_set<int> dfs(int index) {
        if (mp.count(index)) return mp[index];

        unordered_set<int> nextCourses;
        
        for (int i = 0; i < adjList[index].size(); ++i) {
            unordered_set<int> nextCoursesDfs = dfs(adjList[index][i]);
            // cout << "CALL : " << index << " " << adjList[index][i] << " " << nextCoursesDfs.size() << endl;

            nextCourses.insert(nextCoursesDfs.begin(), nextCoursesDfs.end());
        }
        
        nextCourses.insert(index);

        mp[index] = nextCourses;

        return nextCourses;
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        
        for (int i = 0; i < prerequisites.size(); ++i) {
            adjList[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        for (int i = 0; i < numCourses; ++i) {
            if (mp.count(i) == 0) {
                mp[i] = dfs(i);
            }
        }

        vector<bool> ans(queries.size());

        auto it = mp.begin();

        while (it != mp.end()) {
            cout << "AT " << it->first << " : ";

            auto it2 = it->second.begin();

            while (it2 != it->second.end()) {
                cout << *it2;
                it2++;
            }
            it++;

            cout << endl;
        }
        for (int i = 0; i < queries.size(); ++i) {
            ans[i] = mp[queries[i][0]].count(queries[i][1]);
        }

        return ans;
    }
};
