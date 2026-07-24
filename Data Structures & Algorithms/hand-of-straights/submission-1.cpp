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
        if (hand.size() % groupSize != 0) return false;

        unordered_map<int, int> count;

        for (int i = 0; i < hand.size(); ++i) {
            count[hand[i]]++;
        }

        
        for (int i = 0; i < hand.size(); ++i) {
            int start = hand[i];

            while (count[start - 1] > 0) start--;
            
            // Run start up to hand[i]
            while (start <= hand[i]) {
                while (count[start] > 0) {
                    for (int i = start; i < start + groupSize; ++i) {
                        if (count[i] == 0) return false;
                        count[i]--;
                    }
                }
                start++;
            }
        }

        return true;
    }
};
