class Solution {
public:
    vector<vector<int>> res;
    vector<int> temp;

    void dfs(vector<int> subset, int currIdx, int sum, int target) {
        if (sum == target) {
            res.push_back(subset);
            return;
        }
        else if (sum > target) {
            return;
        }

        for (int i = currIdx; i < temp.size(); ++i) {
            vector<int> tempSubset = subset;
            tempSubset.push_back(temp[i]);
            dfs(tempSubset, i, sum + temp[i], target);
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        temp = nums;
        dfs({}, 0, 0, target);

        return res;
    }
};
