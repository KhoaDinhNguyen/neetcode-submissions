class Solution {
public:
    /**
    The idea is to count the the frequency of the gap
    then the number of brick = row - number of gap
    **/
    int leastBricks(vector<vector<int>>& wall) {
        int N = wall.size();

        unordered_map<int, int> mp;

        for (int i = 0; i < N; ++i) {
            int sum = 0;
            for (int j = 0; j < wall[i].size() - 1; ++j) {
                sum += wall[i][j];
                mp[sum]++;
            }    
        }

        if (mp.size() == 0) return N;

        int ans = INT_MAX;

        auto it = mp.begin();

        while (it != mp.end()) {
            ans = min(ans, N - it->second);
            it++;
        }

        return ans;
    }
};