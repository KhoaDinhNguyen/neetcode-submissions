class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;

        for (int i = 0; i < 32; ++i) {
            int currBit = (n & 1) ? 1: 0;
            res = (res << 1) | currBit;
            n = n >> 1;
        }
        
        return res;
    }
};
