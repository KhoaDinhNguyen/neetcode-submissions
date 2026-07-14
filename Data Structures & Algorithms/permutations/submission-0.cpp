class Solution {
public:
    vector<int> temp;
    vector<vector<int>> res;
    void dfs(int depth, set<int>& indices, vector<int>& subset) {
        if (depth == temp.size()) {
            res.push_back(subset);
        }

        for (int i = 0; i < temp.size(); ++i) {
            if (indices.find(temp[i]) == indices.end()) {
                indices.insert(temp[i]);
                subset.push_back(temp[i]);
                dfs(depth + 1, indices, subset);
                indices.erase(temp[i]);
                subset.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        temp = nums;
        set<int> indices;
        vector<int> subset;

        dfs(0, indices, subset);

        return res;
    }
};
