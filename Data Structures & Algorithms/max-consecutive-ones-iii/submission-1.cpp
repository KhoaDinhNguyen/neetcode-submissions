class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int temp = k, N = nums.size();

        int l = 0, r = 0, maxLength = 0;

        // Sliding window
        while (r < N) {
            // If the right is one, continue
            if (nums[r] == 1) {
                maxLength = max(maxLength, r - l + 1);
                r++;
            }
            // If the right is zero and temp > 0, keep expan the window
            else if (nums[r] == 0 && temp > 0) {
                maxLength = max(maxLength, r - l + 1);
                temp--;
                r++;
            }
            else {
                // If the temp == 0, close the window
                while (nums[l] == 1) l++;
                l++;
                temp = 1;
            }
        }

        return maxLength;
    }
};