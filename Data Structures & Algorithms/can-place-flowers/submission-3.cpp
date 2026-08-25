class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int N = flowerbed.size();

        if ((N > 1 && flowerbed[0] + flowerbed[1] == 0) || (N == 1 && flowerbed[0] == 0)) {
            n--;
            flowerbed[0] = 1;
        }

        for (int i = 1; i + 1 < N && n > 0; ++i) {
            if (flowerbed[i - 1] + flowerbed[i + 1] == 0 && flowerbed[i] == 0) {
                n--;
                flowerbed[i] = 1;
            }
        }

        if (N > 1 && flowerbed[N - 2] + flowerbed[N - 1] == 0) n--;

        return n <= 0;
    }
};