class Solution {
public:
    string multiplyByOneNumber(string num1, char num) {
        if (num == '0') return "0";

        string ans = "";

        int i = num1.size() - 1;
        int mem = 0;

        while (i >= 0) {
            int valI = num1[i] - '0';
            int val = num - '0';
            int result = (valI * val + mem) % 10;
            mem = (valI * val + mem) / 10;
            i--;
            ans = to_string(result) + ans;
        }
        cout << mem << endl;
        if (mem > 0) {
            ans = to_string(mem) + ans;
        }

        return ans;
    }

    string addTwoString(string num1, string num2) {
        string ans = "";
        
        int i = num1.size() - 1, j = num2.size() - 1;
        int mem = 0;

        while (i >= 0 || j >= 0) {
            int result = 0;
            if (i >= 0 && j >= 0) {
                int valI = num1[i] - '0', valJ = num2[j] - '0';
                result = (valI + valJ + mem) % 10;
                mem = (valI + valJ + mem) / 10;
                i--;
                j--;
            }
            else if (i >= 0) {
                int valI = num1[i] - '0';
                result = (valI + mem) % 10;
                mem = (valI + mem) / 10;
                i--;
            }
            else if (j >= 0) {
                int valJ = num2[j] - '0';
                result = (valJ + mem) % 10;
                mem = (valJ + mem) / 10;
                j--;
            }

            ans = to_string(result) + ans;
        } 

        if (mem > 0) {
            ans = to_string(mem) + ans;
        }

        return ans;
    }
    string multiply(string num1, string num2) {
        string ans = "0";
        
        int j = num2.size() - 1;

        while (j >= 0) {
            string step = multiplyByOneNumber(num1, num2[j]);
            ans = addTwoString(ans, step);
            num1 = num1 + "0";
            j--;
        }

        return ans;
    }
};
