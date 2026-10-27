class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int N = words.size();

        vector<int> prefixSum(N + 1, 0);

        for (int i = 0; i < N; ++i) {
            prefixSum[i + 1] = prefixSum[i];

            if (isVowel(words[i][0]) && isVowel(words[i][words[i].size() - 1])) {
                prefixSum[i + 1]++;
            }
        }

        int M = queries.size();
        vector<int> res;

        for (int i = 0; i < M; ++i) {
            int start = queries[i][0];
            int end = queries[i][1];

            res.push_back(prefixSum[end + 1] - prefixSum[start]);

        }

        return res;
    }
};