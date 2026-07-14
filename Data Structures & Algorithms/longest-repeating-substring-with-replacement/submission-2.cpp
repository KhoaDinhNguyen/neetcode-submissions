class Solution {
public:
    int characterReplacement(string s, int k) {
        /**
        XYYX
        XXXX -> 4

        AAABABB
        **/
        int ans = 0, N = s.size(), i = 0;
        unordered_map<char, int> mp;
        char mostFreq = s[0];

        for (int j = 0; j < N; ++j) {
            mp[s[j]]++;

            if (mp[s[j]] > mp[mostFreq]) mostFreq = s[j];

            int numOfReplacement = j - i + 1 - mp[mostFreq];

            if (numOfReplacement > k) {
                mp[s[i]]--;
                i++;
            }

            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};
