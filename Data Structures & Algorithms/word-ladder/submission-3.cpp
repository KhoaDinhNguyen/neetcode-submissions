class Solution {
public:
    // Conneted graph + BFS
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (beginWord.size() != endWord.size()) return 0;
        if (beginWord == endWord) return 0;

        vector<string> newWordList;
        bool isIn = false;

        for (const string& word: wordList) {
            if (word.size() == endWord.size() && word != beginWord) {
                newWordList.push_back(word);
            }
            if (word == endWord) isIn = true;
        }

        if (!isIn) return 0;

        int numNodes = newWordList.size();

        vector<vector<int>> adjList(numNodes + 1); // for begin word as well

        for (int i = 0; i < numNodes; ++i) {
            if (isConnected(beginWord, newWordList[i])) {
                adjList[0].push_back(i + 1);
                adjList[i + 1].push_back(0);
            }
        }

        for (int i = 0; i < numNodes; ++i) {
            for (int j = i + 1; j < numNodes; ++j) {
                if (isConnected(newWordList[i], newWordList[j])) {
                    adjList[i + 1].push_back(j + 1);
                    adjList[j + 1].push_back(i + 1);
                }
            }
        }

        // bfs
        int depth = 1;
        queue<int> q;
        vector<bool> visited(numNodes + 1);

        q.push(0);

        while (!q.empty()) {
            int m = q.size();

            for (int i = 0; i < m; ++i) {
                int currNode = q.front();
                q.pop();
                visited[currNode] = true;

                if (currNode != 0 && newWordList[currNode - 1] == endWord) {
                    return depth;
                }

                for (int j = 0; j < adjList[currNode].size(); ++j) {
                    int nextNode = adjList[currNode][j];
                    if (!visited[nextNode]) {
                        q.push(nextNode);
                    }
                }
            }
            depth++;
        }

        return 0;
    }

    bool isConnected(string& s1, string& s2) {
        int diff = 0;

        for (int i = 0; i < s1.size(); ++i) {
            if (s1[i] != s2[i]) diff++;
        }

        return diff <= 1;
    }
};
