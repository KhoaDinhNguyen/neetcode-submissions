class Solution {
public:
    vector<vector<string>> ans;

    bool checkPalindrome(string& s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }

        return true;
    }
    void backtrack(string& s, int i , int j, vector<string>& res) {
        int N = s.size();

        if (j >= N) {
            if (i == j) ans.push_back(res);
            return;
        }

        // Option 1: make partition and start new string        

        // Check palindrome
        if (checkPalindrome(s, i, j)) {
            res.push_back(s.substr(i, j - i + 1));
            backtrack(s, j + 1, j + 1, res);
            res.pop_back();
        }

        // Option 2: Continue
        
        backtrack(s, i, j + 1, res);
    }
    vector<vector<string>> partition(string s) {
        vector<string> res;

        backtrack(s, 0, 0, res);
    
        return ans;
    }

    // Time: Complexity O(2^n * n)
    // Space: Complexity: O(N^2)
};
