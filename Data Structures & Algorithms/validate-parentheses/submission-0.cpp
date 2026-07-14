class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> mp;

        mp['{'] = '}'; 
        mp['['] = ']';
        mp['('] = ')';

        stack<char> st;
        int N = s.size();

        for (int i = 0; i < N; ++i) {
            if (s[i] == '{' || s[i] == '(' || s[i] == '[') st.push(s[i]);
            else {
                if (st.empty()) return false;
                else if (mp[st.top()] != s[i]) return false;
                st.pop();
            }
        }

        if (!st.empty()) return false;

        return true;
    }
};
