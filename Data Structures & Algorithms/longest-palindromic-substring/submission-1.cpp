class Solution {
public:
    string longestPalindrome(string s) {
        int N = s.size(), maxLength = 1;
        string ans = "";
        ans += s[0];

        for (int i = 1; i < N; ++i) {
            int l = i - 1, r = i + 1;

            // Odd Case
            if (r < N && s[l] == s[r]) {
                while (l >= 0 && r < N && s[l] == s[r]) {
                    l--;
                    r++;
                }

                // Return when the string is still palindrome
                l++;
                r--;

                if (r - l + 1 > maxLength) {
                    ans = s.substr(l, r - l + 1);
                    maxLength = ans.size();
                }

            }
            
            // Even case
            if (s[i] == s[i - 1]) {
                int l = i - 1, r = i;

                while (l >= 0 && r < N && s[l] == s[r]) {
                    l--;
                    r++;
                }

                // Return when the string is still palindrome
                l++;
                r--;

                if (r - l + 1 > maxLength) {
                    ans = s.substr(l, r - l + 1);
                    maxLength = ans.size();
                }
            }
        }

        return ans;
    }
};
