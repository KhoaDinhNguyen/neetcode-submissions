class Solution {
public:
    string longestPalindrome(string s) {
        int N = s.size(), maxLength = 1;
        string ans = "";
        ans += s[0];

        for (int i = 1; i < N; ++i) {
            // Odd Case
            int l = i, r = i;
            if (s[l] == s[r]) {
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
            l = i - 1, r = i;
            if (s[l] == s[r]) {
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

    // Space complexity O(1)
    // Time complexity O(N^2)
};
