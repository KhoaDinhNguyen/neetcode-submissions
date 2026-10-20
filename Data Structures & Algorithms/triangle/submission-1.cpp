class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp;

        int N = triangle.size();

        for (int i = 0; i < N; ++i) {
            int m = triangle[i].size();
            dp.push_back(vector<int>(m, 0));
        }

        dp[0][0] = triangle[0][0];

        for (int i = 1; i < N; ++i) {
            int m = dp[i].size();

            dp[i][0] = dp[i - 1][0] + triangle[i][0];
            dp[i][m - 1] = dp[i - 1][m - 2] + triangle[i][m - 1]; 
        }

        for (int i = 1; i < N; ++i) {
            for (int j = 1; j < dp[i].size() - 1; ++j) {
                dp[i][j] = min(dp[i - 1][j - 1] + triangle[i][j], dp[i - 1][j] + triangle[i][j]);
            }
        }

        int res = INT_MAX;

        for (int i = 0; i < dp[N - 1].size(); ++i) {
            res = min(res, dp[N - 1][i]);
        }

        return res;
    }
};