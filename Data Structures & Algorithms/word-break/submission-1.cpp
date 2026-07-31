class Solution {
public:
    /**
    The idea is to run along the string
    - If the prefix match with the one of wordDict
        - Case 1: Cut the string, and then continue the rest
        - Case 2: Continue the string
    **/
    unordered_map<string, bool> stringToBool;
    unordered_set<string> dp;

    bool dfs(string s, unordered_set<string>& wordD) {
        if (s == "") return true;
        if (dp.count(s)) return stringToBool[s];

        int N = s.size();
        string currString = "";
        bool ans = false;

        for (int i = 0; i < s.size(); ++i) {
            currString += s[i];

            if (wordD.count(currString)) {
                string subString = s.substr(i + 1, N - i);
                bool res =  dfs(s.substr(i + 1, N - i), wordD);
                stringToBool[subString] = res;
                dp.insert(subString);

                ans = ans || res;
            }
        }

        return ans;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end());

        return dfs(s, st);    
    }

    // Space O(N^2)
    // Time O(2^N)
};
