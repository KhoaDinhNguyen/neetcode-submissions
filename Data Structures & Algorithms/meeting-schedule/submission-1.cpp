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
    bool canAttendMeetings(vector<Interval>& intervals) {
        if (intervals.size() <= 1) return true;
    
        vector<pair<int, int>> intervals_vector;
        int N = intervals.size();

        for (int i = 0; i < N; ++i) {
            Interval interval_item = intervals[i];
            intervals_vector.push_back({interval_item.start, interval_item. end});
        }

        sort(intervals_vector.begin(), intervals_vector.end());

        int start = intervals_vector[0].first, end = intervals_vector[0].second;

        for (int i = 1; i < N; ++i) {
            int nextStart = intervals_vector[i].first;
            int nextEnd = intervals_vector[i].second;

            if (nextStart < end) return false;

            start = nextStart;
            end = nextEnd;     
        }


        return true;
    }
};
