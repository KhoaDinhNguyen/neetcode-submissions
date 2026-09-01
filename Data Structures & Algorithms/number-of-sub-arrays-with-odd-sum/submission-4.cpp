class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int even = 0, odd = 0, n = arr.size(), total = 0;

        int ans = 0;

        for (int i = 0; i < n; ++i) {
            // even case
            total += arr[i];

            if (total % 2 == 0) {
                ans += odd;
                even++;
            }
            else {
                ans += (even + 1);
                odd++;
            }
        }

        return ans;
    }
};