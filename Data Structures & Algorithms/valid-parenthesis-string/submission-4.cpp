class Solution {
public:
    bool checkValidString(string s) {
        int maxVal = 0, minVal = 0, N = s.size();

        for (int i = 0; i < N; ++i) {
            if (s[i] == '(') {
                maxVal++;
                minVal++;
            }
            else if (s[i] == ')') {
                maxVal--;
                minVal--;
            }
            else {
                maxVal++;
                minVal--;
            }

            if (maxVal < 0) return false;
            if (minVal < 0) minVal = 0;
        }

        return minVal <= 0 &&  0 <= maxVal; 

    }
};
