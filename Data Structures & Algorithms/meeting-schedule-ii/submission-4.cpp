/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    /**
    Another idea is to use two array starts and ends
    - Then we use two pointers s and e
    - Whenever s < e we increase the number of rooms
    **/
    int minMeetingRooms(vector<Interval>& intervals) {
        if (intervals.size() == 0) return 0;
        
        vector<int> start, end;

        int N = intervals.size();
        for (int i = 0; i < N; ++i) {
            start.push_back(intervals[i].start);
            end.push_back(intervals[i].end);
        }

        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        int s = 0, e = 0, activeRoom = 0, res = 0;

        while (s < N) {
            if (start[s] < end[e]) {
                activeRoom++;
                s++;       
            }
            else {
                e++;
                activeRoom--;
            }
            res = max(res, activeRoom);
        }

        return res;
    }
};
