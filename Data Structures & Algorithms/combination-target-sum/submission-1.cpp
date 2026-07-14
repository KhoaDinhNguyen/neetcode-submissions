class Solution {
public:
    vector<vector<int>> res;
    vector<int> temp;

    void dfs(vector<int>& subset, int i, int target) {
        if (target == 0) {
            res.push_back(subset);
            return;
        }
        else if (target < 0 || i >= temp.size()) {
            return;
        }

        subset.push_back(temp[i]);
        dfs(subset, i, target - temp[i]);
        subset.pop_back();
        dfs(subset, i + 1, target);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        temp = nums;
        vector<int> subset;
        dfs(subset, 0, target);

        return res;
    }
};
