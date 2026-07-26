// Definition for a Pair
// class Pair {
// public:
//     int key;
//     string value;
//
//     Pair(int key, string value) : key(key), value(value) {}
// };
class Solution {
public:
    bool comparePair(Pair& i, Pair& j) {
        return i.key <= j.key;
    }

    vector<vector<Pair>> insertionSort(vector<Pair>& pairs) {
        vector<vector<Pair>> res;
        int N = pairs.size();

        for (int i = 0; i < N; ++i) {
            int j = i;
            while (j > 0) {
                // stop when pairs[j] > pairs[j - 1]
                if (comparePair(pairs[j - 1], pairs[j])) break;

                // Else swap pairs[j] and pairs[j - 1]
                swap(pairs[j], pairs[j - 1]);
                j--;

            }

            res.push_back(pairs);
        }

        return res;
    }
};
