class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i = 0, j = heights.size() - 1, ans = 0;

        while (i < j) {
            ans = max(ans, min(heights[i], heights[j]) * (j - i));
            if (heights[i] > heights[j]) {
                j--;
            }
            else {
                // if i == j, move either
                //Since both the walls got their max possible area computed
                // (i.e, no other pairing with walls in middle is going to yield a higher value). either of them is fine
                i++;
            }
        }

        return ans;
    }
};
