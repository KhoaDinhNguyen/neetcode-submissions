class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = INT_MAX;

        while (l < r) {
            int mid = l + (r - l) / 2;
            int hours = 0;

            for (int p: piles) {
                hours += ceil((double)p / mid);
            }

            if (hours <= h) r = mid;
            else l = mid + 1;
        }

        return r;
        
    }
};
