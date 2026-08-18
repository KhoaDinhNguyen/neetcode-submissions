class DisjointSet {
public:
    vector<int> parent;
    vector<int> rank;

    DisjointSet(int n) {
        parent = vector<int>(n, 0);
        rank = vector<int>(n, 0);

        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void do_union(int x, int y) {
        int parentX = find(x), parentY = find(y);

        if (rank[parentX] < rank[parentY]) {
            parent[parentX] = parentY;
        }
        else if (rank[parentX] > rank[parentY]) {
            parent[parentY] = parentX;
        }
        else {
            parent[parentX] = parentY;
            rank[parentY]++;
        }
    } 

    unordered_map<int, vector<int>> listComponent() {
        int N = parent.size();

        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < N; ++i) {
            int parentI = find(i);
            mp[parentI].push_back(i);
        }

        return mp;
    }
};

class Solution {
public:
    unordered_map<string, int> mpStoI;
    unordered_map<int, string> mpItoS;
    unordered_map<string, string> mpEmailToUser;

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int cnt = 0;

        for (int i = 0; i < accounts.size(); ++i) {
            string user = accounts[i][0];

            for (int j = 1; j < accounts[i].size(); ++j) {
                string email = accounts[i][j];

                if (mpStoI.find(email) == mpStoI.end()) {
                    mpEmailToUser[email] = user;
                    mpStoI[email] = cnt;
                    mpItoS[cnt] = email;

                    cnt++;
                }
            }
        }

        DisjointSet djs(mpStoI.size());

        for (int i = 0; i < accounts.size(); ++i) {
            for (int j = 1; j < accounts[i].size() - 1; ++j) {
                string email1 = accounts[i][j];
                string email2 = accounts[i][j + 1];
                djs.do_union(mpStoI[email1], mpStoI[email2]);
            }
        }

        unordered_map<int, vector<int>> mp = djs.listComponent();

        auto it = mp.begin();
        vector<vector<string>> ans;

        while (it != mp.end()) {
            vector<string> row;
            int parentEmail = it->first;

            row.push_back(mpEmailToUser[mpItoS[parentEmail]]);

            for (int i = 0; i < it->second.size(); ++i) {
                row.push_back(mpItoS[it->second[i]]);
            }

            ans.push_back(row);

            ++it;
        }
        
        for (int i = 0; i < ans.size(); ++i) {
            sort(ans[i].begin() + 1, ans[i].end());
        }

        return ans;

    }
    
};