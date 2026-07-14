class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0, i = 0, j = height.size() - 1, leftMax = height[0], rightMax = height[j];

        while (i < j) {
            if (height[i] < height[j]) {
                i++;
                leftMax = max(leftMax, height[i]);
                ans = ans + leftMax - height[i];
            }
            else {
                j--;
                rightMax = max(rightMax, height[j]);
                ans = ans + rightMax - height[j];
            }
        }
        return ans;
    }
};
