class Solution {
public:
    /**
    The idea is that:
    - Only keep valid triplets t where t[i] <= target[i] for i = 0, 1, 2
    - Then, find the target triplets by computing maximum value of each valid triplets
    **/
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int max0 = 0, max1 = 0, max2 = 0, N = triplets.size();

        for (auto t: triplets) {
            if (t[0] > target[0] || t[1] > target[1] || t[2] > target[2]) continue;

            max0 = max(max0, t[0]);
            max1 = max(max1, t[1]);
            max2 = max(max2, t[2]);
        }

        return max0 == target[0] && max1 == target[1] && max2 == target[2];
    }
};
