class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;

        int s1Count[26] = {0}, s2Count[26] = {0};


        for (int i = 0; i < s1.size(); ++i) {
            s1Count[s1[i] - 'a']++;
            s2Count[s2[i] - 'a']++;
        }

        int matches = 0;

        for (int i = 0; i < 26; ++i) {
            if (s1Count[i] == s2Count[i]) matches++;
        }

        int l = 0;
        cout << matches << endl;
        for (int r = s1.size(); r < s2.size(); ++r) {
            if (matches == 26) return true;
            
            int rval = s2[r] - 'a';
            s2Count[rval]++;
            
            if (s1Count[rval] == s2Count[rval]) matches++;
            else if (s1Count[rval] + 1 == s2Count[rval]) matches--;

            int lval = s2[l] - 'a';
            s2Count[lval]--;

            if (s1Count[lval] == s2Count[lval]) matches++;
            else if (s1Count[lval] - 1 == s2Count[lval]) matches--;

            l++;
        }

        return matches == 26;
    }
};
