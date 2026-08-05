class Solution {
public:
    /**
    Idea: Topilogial sort
    **/
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, unordered_set<char>> adjList;
        unordered_map<char, int> indegree;

        for (string word: words) {
            for(char c: word) {
                adjList[c] = unordered_set<char>();
                indegree[c] = 0;
            }
        }

        for (int i = 0; i < words.size() - 1; ++i) {
            string w1 = words[i], w2 = words[i + 1];
            int minLen = min(w1.size(), w2.size());

            if (w1.substr(0, minLen) == w2.substr(0, minLen) && w1.size() > w2.size()) {
                return "";
            }

            for (int j = 0; j < minLen; ++j) {
                if (w1[j] != w2[j]) {
                    if (!adjList[w1[j]].count(w2[j])) {
                        adjList[w1[j]].insert(w2[j]);
                        indegree[w2[j]]++;
                    }
                    break;
                }
            }
        }

        queue<char> q;

        auto it = indegree.begin();

        while (it != indegree.end()) {
            if (it->second == 0) {
                q.push(it->first);
            }
            it++;
        }

        string ans = "";

        while (!q.empty()) {
            char front = q.front();
            ans += front;
            q.pop();
            for (char neighbor: adjList[front]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        return ans.size() == indegree.size()? ans: "";
    }
};
