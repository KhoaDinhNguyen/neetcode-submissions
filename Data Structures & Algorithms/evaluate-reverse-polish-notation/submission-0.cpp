class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        int N = tokens.size();

        for (int i = 0; i < N; ++i) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                int op2 = nums.top();
                nums.pop();
                int op1 = nums.top();
                nums.pop();

                int res = 0;
                if (tokens[i] == "+") res = op1 + op2;
                else if (tokens[i] == "-") res = op1 - op2;
                else if (tokens[i] == "*") res = op1 * op2;
                else if (tokens[i] == "/") res = op1 / op2;

                nums.push(res);
            }
            else {
                nums.push(stoi(tokens[i]));
            }
        }

        return nums.top();
    }
};
