class Solution {
public:
    // Idea, find the first and last index of a character
    // Then, everything inside it is palindrome 

    int countPalindromicSubsequence(string s) {
        int res = 0;

        for (char c = 'a'; c <= 'z'; ++c) {
            int l = s.find(c), r = s.rfind(c);

            if (l == -1 || l == r) continue;

            unordered_set<char> mids;

            for (int j = l + 1; j < r; ++j) {
                mids.insert(s[j]);
            }

            res += mids.size();
        }

        return res;
    }

    // Time complexity O(26 * N)
    // Splace complexity O(1) at most 26 characters
};