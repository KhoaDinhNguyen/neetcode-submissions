class Solution {
public:
    string reorganizeString(string s) {
        auto cmp = [](pair<int, char>& i, pair<int, char>& j) {
            return i.first < j.first;
        };

        priority_queue<pair<int, char>, vector<pair<int, char>>, decltype(cmp)> pq;

        unordered_map<char, int> mp;

        int N = s.size();

        for (int i = 0; i < N; ++i) {
            mp[s[i]]++;
        }

        auto it = mp.begin();

        while (it != mp.end()) {
            pq.push({it->second, it->first});
            it++;
        }

        string ans = "";

        while (ans.size() < N) {
            pair<int, char> p = pq.top();
            pq.pop();

            ans += p.second;

            if (ans.size() == N) return ans;
            else if (pq.size() == 0) return "";

            pair<int, char> sp = pq.top();
            pq.pop();

            ans += sp.second;

            if (p.first > 1) {
                pq.push({p.first - 1, p.second});
            }

            if (sp.first > 1) {
                pq.push({sp.first - 1, sp.second});
            }
            
        }

        return ans;
    }

    // Time Complexity: O(N)
    // Space O(1)
};