class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        // sliding window

        int k = minutes, total = 0, N = customers.size();

        for (int i = 0; i < N; ++i) {
            if (grumpy[i] == 0) total += customers[i];
        }

        int ans = total;
        // first k window
        for (int i = 0; i < k; ++i) {
            if (grumpy[i] == 1) ans += customers[i];
        }

        int currAns = ans;

        for (int r = k; r < N; ++r) {
            int l = r - k;
            if (grumpy[l] == 1) currAns -= customers[l];
            if (grumpy[r] == 1) currAns += customers[r];

            ans = max(currAns, ans);

        }

        return ans;
    }
};