class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, deque<string>> adj;

        for (int i = 0; i < tickets.size(); ++i) {
            adj[tickets[i][0]].push_back(tickets[i][1]);
        }

        for (auto& [src, dests]: adj) {
            sort(dests.rbegin(), dests.rend());
        }

        vector<string> res;

        dfs("JFK", adj, res);

        reverse(res.begin(), res.end());

        return res;
    }

    void dfs(string curr, unordered_map<string, deque<string>>& adj, vector<string>& res) {
        while (!adj[curr].empty()) {
            string dest = adj[curr].back();
            adj[curr].pop_back();
            dfs(dest, adj, res);
        }

        res.push_back(curr);
    }
};
