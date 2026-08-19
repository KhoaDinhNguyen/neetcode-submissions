class Solution {
public:
    string decodeString(string s) {
        stack<string> stringStack;
        stack<int> numStack;

        int k = 0;
        string curr = "";

        for (char c: s) {
            if (isdigit(c)) {
                k = k * 10 + (c - '0');
            }
            else if (c == '[') {
                stringStack.push(curr);
                numStack.push(k);
                k = 0;
                curr = "";
            }
            else if (c == ']') {
                string temp = curr;
                curr = stringStack.top();
                stringStack.pop();

                int cnt = numStack.top();
                numStack.pop();

                for (int i = 0; i < cnt; ++i) {
                    curr += temp;
                }
            }
            else {
                curr += c;
            }
        }

        return curr;
    }
};