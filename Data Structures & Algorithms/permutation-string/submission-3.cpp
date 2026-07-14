class Solution {
public:
    int arr1[26] = {0};
    bool checkWindow(string s2, int start, int end) {
        int arr2[26] = {0};
        for (int i = start; i < end; ++i) {
            arr2[s2[i] - 'a']++;
        }

        for (int i = 0; i < 26; ++i) {
            if (arr1[i] != arr2[i]) return false;
        }

        return true;
    }
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        /**
        le|cab|ee
        abc
        **/

        int N = s1.size(), M = s2.size();

        for (int i = 0; i < N; ++i) {
            arr1[s1[i] - 'a']++;
        }

        for (int i = 0; i <= M - N; ++i) {
            if (checkWindow(s2, i, i + N)) return true;        
        }

        return false;
    }
};
