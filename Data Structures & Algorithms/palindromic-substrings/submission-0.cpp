class Solution {
public:
    int countSubstrings(string s) {
       int N = s.size(), ans = 1;

        for (int i = 1; i < N; ++i) {
            // odd case
            int l = i, r = i;

            if (s[l] == s[r]) {
                while (l >= 0 && r < N && s[l] == s[r]) {
                    ans++;
                    l--;
                    r++;
                }
            }


            // even case
            l = i - 1, r = i;

            if (s[l] == s[r]) {
                while (l >= 0 && r < N && s[l] == s[r]) {
                    ans++;
                    l--;
                    r++;
                }
            }
        }

        return ans;
    }
};
