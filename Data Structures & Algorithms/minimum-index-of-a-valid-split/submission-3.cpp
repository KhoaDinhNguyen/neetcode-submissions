class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int majority = 0, count = 0;

        for (int num: nums) {
            if (count == 0) majority = num;
            count += (num == majority? 1: -1);
        }

        int leftCnt = 0, rightCnt = 0;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == majority) {
                rightCnt++;
            }
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == majority) {
                leftCnt++;
                rightCnt--;
            }
            
            int leftLen = i + 1;
            int rightLen = nums.size() - i - 1;

            if (2 * leftCnt > leftLen && 2 * rightCnt > rightLen) {
                return i;
            }
        }

        return -1;
    }
};