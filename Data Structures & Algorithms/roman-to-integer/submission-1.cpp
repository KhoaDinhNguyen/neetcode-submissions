class Solution {
public:
    /**
    The idea is:
    As we scan left to right, 
    if the current symbol is smaller than the next one, we subtract its value;
    otherwise, we add it

    IV -> -1 + 5 = 4
    **/
    int romanToInt(string s) {
        unordered_map<char, int> roman = {
            {'I', 1}, {'V', 5}, {'X', 10},
            {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
        };

        int ans = 0, N = s.size();

        for (int i = 0; i < N; ++i) {
            if (i + 1 < N && roman[s[i]] < roman[s[i + 1]]) {
                ans -= roman[s[i]];
            }
            else {
                ans += roman[s[i]];
            }
        }

        return ans;
    }
};