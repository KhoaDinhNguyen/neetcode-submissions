class Solution {
public:
    set<vector<int>> st;

    void backtrack(vector<int>& nums, vector<int>& res, vector<bool>& visited) {
        if (res.size() == nums.size()) {
            st.insert(res);
            return;
        }

        int N = nums.size();

        for (int i = 0; i < N; ++i) {
            if (!visited[i]) {
                res.push_back(nums[i]);
                visited[i] = true;
                backtrack(nums, res, visited);

                res.pop_back();
                visited[i] = false;
            }
        }

        
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> res;
        vector<bool> visited(nums.size(), false);

        backtrack(nums, res, visited);

        vector<vector<int>> ans;

        auto it = st.begin();

        while (it != st.end()) {
            ans.push_back(*it);
            it++;
        }

        return ans;
    }
};