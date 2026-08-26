class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        // O(N^2)

        int N = s.size();

        vector<bool> canJump(N, false);

        if (s[0] == '0') canJump[0] = true;

        for (int i = 0; i < N; ++i) {
            if (canJump[i] && s[i] == '0') {
                int l = i + minJump, r = min(i + maxJump, N - 1);
                for (int j = l; j <= r; ++j) {
                    if (s[j] == '1') continue;
                    canJump[j] = true;
                }
            }
        }

        return canJump[N - 1];
    }
};