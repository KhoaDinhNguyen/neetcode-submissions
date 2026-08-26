class Solution {
public:
    int maxScore(string s) {
        int ones = 0, zeros = 0, ans = 0;

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '1') ones++;
        }

        for (int i = 0; i < s.size() - 1; ++i) {
            if (s[i] == '0') zeros++;
            if (s[i] == '1') ones--;

            ans = max(ans, ones + zeros);
        }

        return ans;
    }
};