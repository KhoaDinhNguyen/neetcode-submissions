class Solution {
public:
    vector<vector<bool>> dp;
    vector<vector<bool>> visited;

    bool backtrack(int i, int j, string& s1, string& s2, string& s3) {
        if (i >= s1.size() && j >= s2.size()) return true;
        else if (i >= s1.size()) {
            return s2.substr(j, s2.size() - j + 1) == s3.substr(i + j, s2.size() - j + 1);
        }
        else if (j >= s2.size()) {
            return s1.substr(i, s1.size() - i + 1) == s3.substr(i + j, s1.size() - i + 1);
        } 

        if (visited[i][j]) return dp[i][j];

        visited[i][j] = true;

        if (s3[i + j] != s2[j] && s3[i + j] != s1[i]) return dp[i][j] = false;
        
        dp[i][j] = s3[i + j] == s1[i] ? backtrack(i + 1, j, s1, s2, s3): false;
        dp[i][j] = dp[i][j] || (s3[i + j] == s2[j] ? backtrack(i, j + 1, s1, s2, s3): false);

        return dp[i][j];
    }
    bool isInterleave(string s1, string s2, string s3) {
        if (s3.size() != s1.size() + s2.size()) return false; 
        if (s1 == "") return s3 == s2;
        if (s2 == "") return s3 == s1;

        int N = s1.size(), M = s2.size();

        dp = vector<vector<bool>>(N, vector<bool>(M, false));
        visited = vector<vector<bool>>(N, vector<bool>(M, false));

        backtrack(0, 0, s1, s2, s3);

        return dp[0][0];
    }

    // Time O(N * M)
    // Space O(M * N)
};
