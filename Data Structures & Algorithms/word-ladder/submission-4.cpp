class Solution {
public:
    // Conneted graph + BFS
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (beginWord.size() != endWord.size()) return 0;
        if (beginWord == endWord) return 0;

        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<string> q;

        int depth = 0;
        q.push(beginWord);

        while (!q.empty()) {
            depth++;
            int m = q.size();

            for (int i = 0; i < m; ++i) {
                string node = q.front();
                q.pop();

                if (node == endWord) return depth;

                for (int j = 0; j < node.size(); ++j) {
                    char original = node[j];

                    for (char c = 'a'; c <= 'z'; ++c) {
                        if (c == original) continue;
                        node[j] = c;

                        if (st.find(node) != st.end()) {
                            q.push(node);
                            st.erase(node);
                        }
                    }

                    node[j] = original;
                }
            }
        }

        return 0;
    }
    // Time O(N * M^2)

};
