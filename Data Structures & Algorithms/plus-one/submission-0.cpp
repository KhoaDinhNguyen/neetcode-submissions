class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int N = digits.size(), carry = 1;

        for (int i = N - 1; i >= 0; --i) {
            int val = digits[i] + carry;
            digits[i] = val % 10;
            carry = val / 10;
        }

        if (carry == 1) {
            digits.insert(digits.begin(), 1);
        }

        return digits;
    }
};
