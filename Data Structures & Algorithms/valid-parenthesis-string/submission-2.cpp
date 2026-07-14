class Solution {
public:
    bool checkValidString(string s) {
        int leftMin = 0, leftMax = 0;

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                leftMin = leftMin + 1;
                leftMax = leftMax + 1;
            }
            else if (s[i] == ')') {
                leftMax = leftMax - 1;
                leftMin = leftMin - 1;
            }
            else {
                leftMax = leftMax + 1;
                leftMin = leftMin - 1;
            }

            if (leftMax < 0) return false;
            if (leftMin < 0) leftMin = 0; // s = ( * ) (
        }

        return leftMin <= 0 && 0 <= leftMax;
    }
};
