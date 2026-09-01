class Solution {
public:
    bool validate(vector<int>& piles, int rate, int h) {
        int n = piles.size(), total = 0;

        for (int i = 0; i < n; ++i) {
            total += (piles[i] / rate + (piles[i] % rate != 0));
        }

        return total <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = INT_MAX;

        while (l < r) {
            int m = l + (r - l) / 2;

            bool eat = validate(piles, m, h);

            if (eat) r = m;
            else l = m + 1; 
        }

        return r;
    }
};
