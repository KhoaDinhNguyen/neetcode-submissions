class Solution {
public:
    string multiply(string num1, string num2) {
        int N = num1.size(), M = num2.size();

        vector<int> result(M + N, 0);
        
        for (int i = N - 1; i >= 0; --i) {
            for (int j = M - 1; j >= 0; --j) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int sum = mul + result[i + j + 1];

                result[i + j + 1] = sum % 10;
                result[i + j] += sum / 10;
            } 
        }

        string ans = "";

        for (int num: result) {
            if (ans == "" && num == 0) continue;
            ans += to_string(num);
        }

        return ans == "" ? "0": ans;
    }

    // Time O(M * N)
    // Space O(M + N)
};
