class Solution {
public:
    vector<vector<int>> dp;

    int minDistance(string word1, string word2) {
        dp = vector<vector<int>>(word1.size() + 1, vector<int>(word2.size() + 1, -1));

        dfs(0, 0, word1.size(), word2.size(), word1, word2);

        return dp[0][0];
    }
    int dfs(int i, int j, int n, int m, string& word1, string& word2) {
        if (dp[i][j] != -1) return dp[i][j];
        else if (i == n) return dp[i][j] =  m - j;
        else if (j == m) return dp[i][j] = n - i;
        else if (word1[i] == word2[j]) return dp[i][j] = dfs(i + 1, j + 1, n, m, word1, word2);

        int res = min(dfs(i + 1, j, n, m, word1, word2), dfs(i, j + 1, n, m, word1, word2));
        res = min(res, dfs(i + 1, j + 1, n, m, word1, word2));

        return dp[i][j] = res + 1;
    }
};
