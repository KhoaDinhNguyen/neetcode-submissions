class Solution {
public:
    vector<int> memo = vector<int>(100, -1);
    int decode(string& s, int i) {
        int N = s.size();

        if (i >= N) return 1;
        if (s[i] == '0') return 0;
        if (memo[i] != -1) return memo[i];

        int takeOneCharacter = decode(s, i + 1);
        int takeTwoCharacter = 0;

        if (i + 1 < N) {
            bool canTakeTwoCharacter = (s[i] == '1') || (s[i] == '2' && '0' <= s[i + 1] && s[i + 1] <= '6');
            if (canTakeTwoCharacter) {
                takeTwoCharacter = decode(s, i + 2);
            }
        }
       
        return memo[i] = takeOneCharacter + takeTwoCharacter;
    }
    int numDecodings(string s) {
        return decode(s, 0);
    }
};
