class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<vector<int>> tasksIdx(tasks.size());

        for (int i = 0; i < tasks.size(); ++i) {
            tasksIdx[i] = {tasks[i][0], tasks[i][1], i};
        }

        sort(tasksIdx.begin(), tasksIdx.end());

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        int currTime = 0, N = tasks.size(), nextTask = 0;

        vector<int> ans;

        while (nextTask < N || !pq.empty()) {
            if (pq.empty() && currTime < tasksIdx[nextTask][0]) {
                currTime = tasksIdx[nextTask][0];
            }

            while (nextTask < N && currTime >= tasksIdx[nextTask][0]) {
                pq.push({tasksIdx[nextTask][1], tasksIdx[nextTask][2]});
                nextTask++;
            }

            int t = pq.top().first, taskIdx = pq.top().second;
            pq.pop();

            ans.push_back(taskIdx);
            currTime += t;
        }

        return ans;
    }
};