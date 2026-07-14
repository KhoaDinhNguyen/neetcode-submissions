class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int N = s.size();
        unordered_map<char, int> mp;

        int i = 0, ans = 0, len = 0;

        for (int j = 0; j < N; ++j) {
            if (mp.find(s[j]) != mp.end()) {
                i = max(mp[s[j]] + 1, i);
            }
            mp[s[j]] = j;
            ans = max(ans, j - i + 1);
        }

        return ans;
    }
};
