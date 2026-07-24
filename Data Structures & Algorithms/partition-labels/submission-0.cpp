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
        int idx = 0, start = 0, N = s.size();
        

        while (idx < N) {
            int lastIndex = lastIndexes[s[idx] - 'a'];
            // cout << "Before loop: " <<  s[start] << " " << lastIndex << endl;
            if (lastIndex == N) {
                res.push_back(N - start);
                return res;
            }

            while (idx < lastIndex) {
                lastIndex = max(lastIndex, lastIndexes[s[idx] - 'a']);
                
                // cout << "Inside loop: " << s[idx] << " " << lastIndex << endl;
                
                if (lastIndex == N) {
                    res.push_back(N - start);
                    return res;
                }
                idx++;
            }
            // cout << "After loop: " <<  s[start] << " " << lastIndex << endl;
            // if current index == lastIndex, it each letter has appears in one substring
            res.push_back(idx - start + 1);
            idx = idx + 1;
            start = idx;
        }

        return res;
    }
};
