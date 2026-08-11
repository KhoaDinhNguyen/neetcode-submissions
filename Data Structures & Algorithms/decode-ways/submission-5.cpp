class Solution {
public:
    vector<int> dp;
    int numDecodings(string& s, int i) {
        if (i >= s.size()) return 1;
        
        if (dp[i] != -1) return dp[i];
        if (s[i] == '0') return dp[i] = 0;

        int res = 0;

        // option 1: take 1 character
        int option1 = numDecodings(s, i + 1);

        if (option1 > 0) res += option1;
        
        // option 2: take 2 characters
        int option2 = (i + 1 < s.size() && s[i] == '1') ? numDecodings(s, i + 2): 0;
        if (option2 > 0) res += option2;

        int option3 = (i + 1 < s.size() && s[i] == '2' && '0' <= s[i + 1] && s[i + 1] <= '6') ? numDecodings(s, i + 2): 0;

        if (option3 > 0) res += option3;

        return dp[i] = res;
    }
    int numDecodings(string s) {
        dp = vector<int>(s.size(), -1);

        numDecodings(s, 0);

        return dp[0] == -1 ? 0 : dp[0];
    }
};
