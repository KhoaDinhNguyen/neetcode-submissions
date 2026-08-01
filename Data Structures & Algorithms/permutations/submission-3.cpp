class Solution {
public:
    vector<vector<int>> ans; 
    void backtrack(vector<int>& nums, unordered_set<int>& st, vector<int>& res) {
        int N = nums.size();

        if (res.size() == N) {
            ans.push_back(res);

            return;
        }

        for (int i = 0; i < N; ++i) {
            if (st.find(nums[i]) == st.end()) {
                res.push_back(nums[i]);
                st.insert(nums[i]);
                backtrack(nums, st, res);

                res.pop_back();
                st.erase(nums[i]);
            }
        }

    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> res;
        unordered_set<int> st;
        backtrack(nums, st, res);
        return ans;
    }
};
