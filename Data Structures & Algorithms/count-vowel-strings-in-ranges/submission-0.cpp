class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int N = words.size();

        vector<int> prefixSum(N, 0);
        
        if (isVowel(words[0][0]) && isVowel(words[0][words[0].size() - 1])) {
            prefixSum[0] = 1;
        }

        for (int i = 1; i < N; ++i) {
            prefixSum[i] = prefixSum[i - 1];

            if (isVowel(words[i][0]) && isVowel(words[i][words[i].size() - 1])) {
                prefixSum[i]++;
            }
        }

        int M = queries.size();
        vector<int> res;

        for (int i = 0; i < M; ++i) {
            int start = queries[i][0];
            int end = queries[i][1];

            if (start == 0) {
                res.push_back(prefixSum[end]);
            }
            else {
                res.push_back(prefixSum[end] - prefixSum[start - 1]);
            }
        }

        return res;
    }
};