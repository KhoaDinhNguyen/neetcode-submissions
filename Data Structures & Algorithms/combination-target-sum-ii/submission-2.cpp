class Solution {
public:
    vector<vector<int>> res;
    vector<int> temp;

    void dfs(vector<int>& subset, int i, int target) {
        if (target == 0) res.push_back(subset);
        else if (target < 0 || i >= temp.size()) return;
        else {
            subset.push_back(temp[i]);
            dfs(subset, i + 1, target - temp[i]);
            while (i + 1 < temp.size() && temp[i] == temp[i + 1]) {
                i++;
            }
            subset.pop_back();
            dfs(subset, i + 1, target);
           
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        temp = candidates;
        sort(temp.begin(), temp.end());
        vector<int> subset;
        dfs(subset, 0, target);

        return res;    
    }
};
