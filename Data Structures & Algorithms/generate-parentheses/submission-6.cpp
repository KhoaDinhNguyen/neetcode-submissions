class Solution {
public:
    void dfs(int n, int open, int close, string& prev, set<string>& st) {
        if (close == n && open == n) {
            st.insert(prev);
            return;
        }

        if (open < n) {
            string next1 = prev + "(";
            dfs(n, open + 1, close, next1, st);
        }
        if (close < open) {
            string next2 = prev + ")";
            dfs(n, open, close + 1, next2, st);
        }
    }
    vector<string> generateParenthesis(int n) {
        string init = "";
        set<string> st;

        dfs(n, 0, 0, init, st);

        vector<string> ans;

        auto it = st.begin();

        while (it != st.end()) {
            ans.push_back(*it);
            it++;
        }

        return ans;
    }
};
