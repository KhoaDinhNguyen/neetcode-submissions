class Solution {
public:
    vector<vector<int>> res;
    vector<int> NUMS;

    void dfs(int i, vector<int> curr) {
        if (i == NUMS.size()) {
            res.push_back(curr);
            return;
        }
        vector<int> change = curr;
        change.push_back(NUMS[i]);

        // add empty
        dfs(i + 1, curr);
        // add next value
        dfs(i + 1, change);
    } 
    vector<vector<int>> subsets(vector<int>& nums) {
        NUMS = nums;
        dfs(0, {});

        return res;
    }
};
