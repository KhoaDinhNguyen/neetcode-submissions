class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int, int> left, right;
        int n = nums.size();

        for (int num: nums) {
            right[num]++;
        }

        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            left[num]++;
            right[num]--;
            
            int leftLen = i + 1;
            int rightLen = nums.size() - i - 1;

            if (2 * left[num] > leftLen && 2 * right[num] > rightLen) {
                return i;
            }
        }

        return -1;
    }
};