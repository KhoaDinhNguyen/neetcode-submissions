class Solution {
public:
    int minSwaps(string s) {
        int extraClose = 0, maxClose = 0;

        for (auto c: s) {
            if (c == '[') extraClose--;
            else extraClose++;

            maxClose = max(maxClose, extraClose);
        }

        return maxClose % 2 == 0? maxClose / 2: maxClose / 2 + 1;
    }
};