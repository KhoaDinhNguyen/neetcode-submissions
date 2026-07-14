class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int N = s.size();
        unordered_set<char> st;

        int i = 0, ans = 0, len = 0;

        for (int j = 0; j < N; ++j) {
            while (st.find(s[j]) != st.end()) {
                st.erase(s[i]);
                i++;
                len--;
            }
            
            len++;
            ans = max(ans, len);
            st.insert(s[j]);
        }

        return ans;
    }
};
