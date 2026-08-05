class Solution {
public:
    int compress(vector<char>& chars) {
        if (chars.size() == 1) return 1;

        char currentChar = chars[0];
        int count = 1;
        int ans = 0;
        int j = 0;
        
        for (int i = 1; i < chars.size(); ++i) {
            if (chars[i] == currentChar) {
                count++;
            }
            else {
                chars[j++] = currentChar;
                if (count == 1) {
                    ans += 1;
                }
                else {
                    string count_string = to_string(count);
                    for (int k = 0; k < count_string.size(); ++k) {
                        chars[j++] = count_string[k];
                    }
                    ans += (1 + count_string.size());
                }
                
                count = 1;
                currentChar = chars[i];
            }
        }

        chars[j++] = currentChar;
        if (count == 1) {
            ans += 1;
        }
        else {
            string count_string = to_string(count);
            for (int k = 0; k < count_string.size(); ++k) {
                chars[j++] = count_string[k];
            }
            ans += (1 + count_string.size());
        }

        return ans;

    }
};