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

        int goal = nums.size() - 1;

        for (int i = nums.size() - 2; i >= 0; --i) {
            if (i + nums[i] >= goal) goal = i;
        }

        return goal == 0;
    }
};
