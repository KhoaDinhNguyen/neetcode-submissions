class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int i = 0, j = 1;

        vector<int> res(nums.size());

        for (int num : nums) {
            if (num > 0) {
                res[i] = num;
                i = i + 2;
            }
            else {
                res[j] = num;
                j = j + 2;
            }
        }

        return res;
    }
};