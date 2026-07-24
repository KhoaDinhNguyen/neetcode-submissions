class Solution {
public:
    /**
    The idea is that minimum value only have one type of group
    For instance if an array 1 2 2 3 4 5
    1 is minimum value and the group will be [1, 2, 3]
    while 2 is not a minimum value and group could be [1, 2 ,3] or [2, 3 , 4]

    So the algorithm is every time, pick the minimum from the array
    and find the group
    **/
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (groupSize == 1) return true;
        if (hand.size() == 1) return true;

        sort(hand.begin(), hand.end());
        map<int, int> mp;

        for (int i = 0; i < hand.size(); ++i) {
            mp[hand[i]]++;
        }

        
        for (int i = 0; i < hand.size(); ++i) {
            if (mp[hand[i]] > 0) {
                int k = groupSize;
                int val = hand[i];
                while (k > 0) {
                    if (mp[val] == 0) return false;
                    mp[val]--;
                    k--;
                    val++;
                }
            }
        }

        return true;
    }
};
