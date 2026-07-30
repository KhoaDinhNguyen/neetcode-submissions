class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        threshold *= k;
        int window = 0, res = 0;

        for (int i = 0; i < k - 1; ++i) {
            window += arr[i];
        }

        for (int i = k - 1; i < arr.size(); ++i) {
            window += arr[i];
            
            if (window >= threshold) res++;

            window -= arr[i - (k - 1)];
        }

        return res;
    }

    // Space complexity O(1)
    // Time complexity O(N)
};