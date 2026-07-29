class Solution {
public:
    vector<vector<string>> ans;

    bool checkPalindrome(string s) {
        int i = 0, j = s.size() - 1;

        while (i < j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }

        return true;
    }
    void backtrack(string& s, int idx, string prevWord, vector<string> res) {
        int N = s.size();

        if (idx == N) {
            if (res.size() > 0 && prevWord == "") ans.push_back(res);
            return;
        }

        // Option 1: make partition and start new string        
        string word = prevWord + s[idx];

        // Check palindrome
        if (checkPalindrome(word)) {
            res.push_back(word);
            backtrack(s, idx + 1, "", res);
            res.pop_back();
        }

        // Option 2: Continue
        
        backtrack(s, idx + 1, word, res);
    }
    vector<vector<string>> partition(string s) {
        vector<string> res;

        backtrack(s, 0, "", res);
    
        return ans;
    }
};
