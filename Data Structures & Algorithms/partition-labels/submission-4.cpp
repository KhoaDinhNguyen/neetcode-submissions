class Solution {
public:
    /**
    The idea is that if the last index is the current index, push the length into result
    **/
    vector<int> partitionLabels(string s) {
        int lastIndexes[26] = {};

        for (int i = 0 ; i < s.size(); ++i){
            lastIndexes[s[i] - 'a'] = i;
        }

        vector<int> res;
        int size = 0, N = s.size(), end = 0;
        

        for (int i = 0; i < N; ++i) {
            size++;
            end = max(end, lastIndexes[s[i] - 'a']);

            if (end == i) {
                res.push_back(size);
                size = 0;
            }
        }

        return res;
    }
};
