class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int, int> mp;
        vector<vector<int>> freq(nums.size() + 1, vector<int>());

        for (int i = 0; i < nums.size(); ++i) {
            mp[nums[i]]++;
        }

        auto it = mp.begin();

        while (it != mp.end()) {
            cout << it->second << endl;
            freq[it->second].push_back(it->first);
            it++;
        }

        for (int i = nums.size(); i >= 1; --i) {
            cout << i;
            if (freq[i].size() > 0) {
                for (int j = 0; j < freq[i].size() && k > 0; ++j) {
                    ans.push_back(freq[i][j]);
                    k--;
                }
                if (k == 0) {
                    break;
                }
            }
        }
        return ans;
    }
};
