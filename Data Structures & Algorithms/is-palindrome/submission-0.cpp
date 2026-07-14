class Solution {
public:
    bool isPalindrome(string s) {
        int N = s.size();
        
        string newString = "";

        for (int i = 0; i < N; ++i) {
            if ('0' <= s[i] && s[i] <= '9') newString += s[i];
            else if ('a' <= s[i] && s[i] <= 'z') newString += s[i];
            else if ('A' <= s[i] && s[i] <= 'Z') newString += (s[i] + 32);
        }

        int M = newString.size();

        for (int i = 0; i < M / 2; ++i) {
            if(newString[i] != newString[M - 1 - i]) return false;
        }

        return true;
    }
};
