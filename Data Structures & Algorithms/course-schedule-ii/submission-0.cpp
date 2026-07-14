class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        vector<vector<int>> adj(numCourses, vector<int>());
        vector<int> inorder(numCourses, 0);

        for (int i = 0; i < prerequisites.size(); ++i) {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);    
            inorder[prerequisites[i][0]]++;
        }

        queue<int> q;

        for (int i = 0 ; i < numCourses; ++i) {
            if (inorder[i] == 0) q.push(i);
        }

        while (!q.empty()) {
            int top = q.front();
            q.pop();
            ans.push_back(top);
            
            vector<int> adjNode = adj[top];
            for (int i = 0; i < adjNode.size(); ++i) {
                inorder[adjNode[i]]--;
                if (inorder[adjNode[i]] == 0) q.push(adjNode[i]);
            }
        }

        if (ans.size() < numCourses) return {};

        return ans;       
    }
};
