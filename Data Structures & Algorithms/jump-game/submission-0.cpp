class Solution {
public:
    bool canJump(vector<int>& nums) {
        /**
        1 2 2 0 0

        1 0 0 0 0

        Observation:
        - If you jump at i, you can jump at i - 1
        **/

        if (nums.size() == 1) return true;
        else if (nums[0] == 0) return false;

        int maxJumpIdx = nums[0];

        for (int i = 1; i < nums.size() && i <= maxJumpIdx; ++i) {
            maxJumpIdx = max(maxJumpIdx, i + nums[i]);
        }

        return maxJumpIdx >= nums.size() - 1;
    }
};
