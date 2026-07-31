class Solution {
public:
    /**
    The idea is to run along the string
    - If the prefix match with the one of wordDict
        - Case 1: Cut the string, and then continue the rest
        - Case 2: Continue the string
    **/
    unordered_map<string, bool> dp;

    bool dfs(string s, unordered_set<string>& wordD) {
        if (s == "") return true;
        if (dp.find(s) != dp.end()) return dp[s];

        int N = s.size();
        string currString = "";
        bool ans = false;

        for (int i = 0; i < s.size(); ++i) {
            currString += s[i];

            if (wordD.count(currString)) {
                string subString = s.substr(i + 1, N - i);
                bool res =  dfs(s.substr(i + 1, N - i), wordD);
                dp[subString] = res;

                ans = ans || res;
            }
        }

        return ans;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end());

        return dfs(s, st);    
    }

    /**
    DP states: O(N) (one for each suffix)
    Time per state: O(N ^ 2) because of the loop and repeated substr() copying
    Total time: O(N ^ 3)
    Space: O(N ^ 2) due to storing copied suffix strings and recursion stack
    **/
};
