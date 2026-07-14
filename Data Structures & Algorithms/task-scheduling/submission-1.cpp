class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;
        queue<pair<char, int>> q;

        auto compare = [](pair<char,int>& i, pair<char,int>& j) {
            if (i.second == j.second) return i.first > j.first;
            else return i.second < j.second;
        };

        priority_queue<pair<char,int>,
                        vector<pair<char,int>>,
                        decltype(compare)> pq(compare);

        for (int i = 0; i < tasks.size(); ++i) freq[tasks[i]]++;
        for (auto f: freq) pq.push({f.first, f.second});

        int time = 0;

        while (!q.empty() || !pq.empty()) {
            if (!q.empty() && q.front().second <= time) {
                char task = q.front().first;
                q.pop();
                pq.push({task, freq[task]});
            }
            if (!pq.empty()) {
                char task = pq.top().first;
                pq.pop();
                freq[task]--;

                if (freq[task] > 0) {
                    q.push({task, time + n + 1});
                }
            }
            time++;
        }

        return time;
    }
};
