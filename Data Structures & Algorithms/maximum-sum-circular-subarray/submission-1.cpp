class Solution {
public:
    /**
    The idea is to find minimum value subarray, then we know that other value create maximum value
    **/
    int maxSubarraySumCircular(vector<int>& nums) {
        int N = nums.size();

        int globMax = nums[0], globMin = nums[0];
        int currMax = 0, currMin = 0;
        int total = 0;


        for (auto num: nums) {
            currMax = max(num, currMax + num);
            currMin = min(num, currMin + num);
            total += num;
            globMax = max(currMax, globMax);
            globMin = min(currMin, globMin);
        }
        
        return globMax < 0? globMax: max(globMax, total - globMin);
    }
};