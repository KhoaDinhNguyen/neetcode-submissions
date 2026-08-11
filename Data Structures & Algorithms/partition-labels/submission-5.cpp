class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> lastIdx(26, -1);

        for (int i = 0; i < s.size(); ++i) {
            lastIdx[s[i] - 'a'] = i;
        }

        vector<int> ans;

        int l = 0, r = 0;

        for (int i = 0; i < s.size(); ++i) {
            r = max(r, lastIdx[s[i] - 'a']);

            if (i == r) {
                ans.push_back(r - l + 1);
                l = r + 1;
            }
        }

        return ans;
    }
};
