class Solution {
public:
    vector<vector<int>> res;
    vector<int> NUMS;

    void dfs(int i, vector<int>& curr) {
        if (i == NUMS.size()) {
            res.push_back(curr);
            return;
        }
        
        // add this value
        curr.push_back(NUMS[i]);
        dfs(i + 1, curr);
        // add empty
        curr.pop_back();
        dfs(i + 1, curr);
    } 
    vector<vector<int>> subsets(vector<int>& nums) {
        NUMS = nums;
        vector<int> subset;
        dfs(0, subset);

        return res;
    }
};
