class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        if (s[0] == '1' || s[s.size() - 1] == '1') return false;

        int N = s.size();
        vector<bool> dp(N, false);

        dp[0] = true;
        int j = 0; // farthest point

        for (int i = 0; i < N; ++i) {
            if (!dp[i]) continue;

            j = max(j, i + minJump);

            while (j <= min(i + maxJump, N - 1)) {
                if (s[j] == '0') {
                    dp[j] = true;
                }
                j++;
            }
        }

        return dp[N - 1];
    }
};