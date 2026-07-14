class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty()) return "";

        unordered_map<char, int> window, countT;

        for (char c: t) {
            countT[c]++;
        }

        int have = 0, need = countT.size(), l = 0, N = s.size(), resLen = INT_MAX;
        pair<int, int> ans = {-1 , -1};
        
        for (int r = 0; r < N; ++r) {
            window[s[r]]++;

            if (countT.count(s[r]) && countT[s[r]] == window[s[r]]) have++;

            while (have == need) {
                if (r - l + 1 < resLen) {
                    resLen = r - l + 1;
                    ans = {l , r};
                }

                window[s[l]]--;

                if (countT.count(s[l]) && countT[s[l]] > window[s[l]]) have--;

                l++;
            }
        }

        return resLen == INT_MAX ? "" : s.substr(ans.first, resLen);
    }
};
