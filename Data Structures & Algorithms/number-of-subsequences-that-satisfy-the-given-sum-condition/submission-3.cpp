class Solution {
public:
    long long MOD = pow(10, 9) + 7;
    int sum(int a, int b) {
        return ((a % MOD) + (b % MOD)) % MOD;
    }

    int numSubseq(vector<int>& nums, int target) {
        int N = nums.size();
         

        sort(nums.begin(), nums.end());
        int ans = 0;

        vector<int> pow2(N, 1);

        for (int i = 1; i < N; ++i) {
            pow2[i] = (pow2[i - 1] * 2 % MOD);
        }
        
        int left = 0, right = N - 1;
        
        while (left <= right) {
            if (nums[left] + nums[right] <= target) {
                ans = (ans + pow2[right - left]) % MOD;
                left++;
            }
            else {
                right--;
            }
        }
       

        return ans;

    }
};