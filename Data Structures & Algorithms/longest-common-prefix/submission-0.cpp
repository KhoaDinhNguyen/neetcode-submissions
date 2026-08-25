class Solution {
public:
    string prefix(string& s1, string& s2) {
        int i = 0, j = 0, n = s1.size(), m = s2.size();
        string prefix = "";

        while (i < n && j < m && s1[i] == s2[j]) {
            prefix += s1[i];
            i++;
            j++;
        }

        return prefix;
    }

    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
    
        return prefix(strs[0], strs[strs.size() - 1]);
    }
};