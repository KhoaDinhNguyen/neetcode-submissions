class Solution {
public:
    int countPalindromicSubsequence(string s) {
        if (s.size() < 3) return 0;

        int ans = 0;

        for (char c = 'a'; c <= 'z'; ++c) {
            int l = s.find(c), r = s.rfind(c);

            if (r == -1 || l == r) continue;

            unordered_set<int> mids;
            
            for (int i = l + 1; i < r; ++i) {
                mids.insert(s[i]);
            }

            ans += mids.size();
        }

        return ans;
    }
};