class Solution {
public:
    bool isAlphabetic(char c) {
        if ('0' <= c && c <= '9') return true;
        else if ('a' <= c && c <= 'z') return true;
        else if ('A' <= c && c <= 'Z') return true;
        return false;
    }

    bool isPalindrome(string s) {
        int N = s.size(), i = 0, j = N - 1;
        
        while (i < j) {
            if (!isAlphabetic(s[i])) i++;
            else if (!isAlphabetic(s[j])) j--;
            else if (tolower(s[i]) != tolower(s[j])) {
                return false;
            }
            else {
                i++;
                j--;
            }
        }

        return true;
    }
};
