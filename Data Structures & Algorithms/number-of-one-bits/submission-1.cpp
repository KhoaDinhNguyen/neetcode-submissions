class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0, i = 0;

        while (i < 32) {
            if (n & 1) res++;
            n = n >> 1;
            i++;
        }

        return res;
    }
};
