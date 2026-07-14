class Solution {
public:
    vector<vector<int>> res;
    vector<int> temp;

    void dfs(int i, vector<int>& subset) {
        if (i >= temp.size()) {
            res.push_back(subset);
            return;
        }

        // Add value
        subset.push_back(temp[i]);
        dfs(i + 1, subset);

        // Not add value
        subset.pop_back();
        while (i + 1 < temp.size() && temp[i] == temp[i + 1]) i++;
        dfs(i + 1, subset);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        temp = nums;
        sort(temp.begin(), temp.end());
        vector<int> subset;
        dfs(0, subset);

        return res;
    }
};
