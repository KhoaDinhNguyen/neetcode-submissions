class Solution {
private:
    unordered_map<string, string> mp_encode;
    unordered_map<string, string> mp_decode;
    int M = 0;
public:
    string encode(vector<string>& strs) {
        int N = strs.size();

        string encode_string = "";

        for (int i = 0; i < N; ++i) {
            string code = "" + to_string(M);
            mp_encode[strs[i]] = code;
            mp_decode[code] = strs[i];
            if (i == N - 1) {
                encode_string += code;
            }
            else {
                encode_string += code + "_";
            }
            M++;
        }

        return encode_string;
    }

    vector<string> decode(string s) {
        if (s.size() == 0) return {};

        vector<string> res;

        int i = 0, N = s.size();
        string code = "";

        while (i < N) {
            if (s[i] == '_') {
                res.push_back(mp_decode[code]);
                code = "";
            }
            else {
                code += s[i];
            }
            i++;
        }

        res.push_back(mp_decode[code]);

        return res;

    }
};
