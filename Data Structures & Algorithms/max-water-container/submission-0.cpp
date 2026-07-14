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
                i++;
            }
        }

        return ans;
    }
};
