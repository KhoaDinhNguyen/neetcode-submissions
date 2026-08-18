class Solution {
public:
    unordered_map<char, vector<char>> mp = 
    {{'2', {'a', 'b', 'c'}},
     {'3', {'d', 'e', 'f'}},
     {'4', {'g', 'h', 'i'}},
     {'5', {'j', 'k', 'l'}},
     {'6', {'m', 'n', 'o'}},
     {'7', {'p', 'q', 'r', 's'}},
     {'8', {'t', 'u', 'v'}},
     {'9', {'w', 'x', 'y', 'z'}}
    };
    vector<string> ans;

    void backtrack(string& currString, string& digits){
        if (currString.size() == digits.size()) {
            ans.push_back(currString);
            return;
        }

        char digit = digits[currString.size()];

        for (int i = 0; i < mp[digit].size(); ++i) {
            currString += mp[digit][i];
            backtrack(currString, digits);
            currString.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return {};

        string currString = "";
        backtrack(currString, digits);

        return ans;
    }
};
