class Solution {
public:
    vector<vector<int>> dp;
    bool stoneGame(vector<int>& piles) {
        int N = piles.size();

        dp = vector<vector<int>>(N, vector<int>(N, -1));

        int sum = 0;

        for (int i = 0; i < N; ++i) {
            sum += piles[i];
        } 

        int aliceScore = dfs(0, N - 1, piles);

        return aliceScore > sum - aliceScore;

    }

    int dfs(int l, int r, vector<int>& piles) {
        int N = piles.size();

        if (l > r) return 0;
        if (dp[l][r] != -1) return dp[l][r];

        bool even = (r - l + 1) % 2 == 0;

        int left = even? piles[l] : 0;
        int right = even? piles[r] : 0;

        return dp[l][r] = max(dfs(l + 1, r, piles) + left, dfs(l, r - 1, piles) + right);
    }
};