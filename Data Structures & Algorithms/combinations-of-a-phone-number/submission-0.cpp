class Solution {
public:
    vector<string> res;
    string temp;
    unordered_map<char, string> mp = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
    void dfs(int currIdx, string& subset) {
        if (currIdx >= temp.size()) {
            res.push_back(subset);
            return;
        }

        string curr = mp[temp[currIdx]];

        for (int i = 0; i < curr.size(); ++i) {
            subset.push_back(curr[i]);
            dfs(currIdx + 1, subset);
            subset.pop_back();
        }

    }
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        temp = digits;
        string subset = "";

        dfs(0, subset);

        return res;
    }
};
