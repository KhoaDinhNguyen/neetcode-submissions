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
    The idea is to create a vector<pair<int, int>> room contain start and end time
    For each intervals, iterate through each room
    - if the room end <= intervals.start => then that room is available for that meeting
    **/
    int minMeetingRooms(vector<Interval>& intervals) {
        if (intervals.size() == 0) return 0;
        
        // Sort interval
        sort(intervals.begin(), intervals.end(), [](Interval&x, Interval&y){
            if (x.start == y.start) return x.end < y.end;
            else return x.start < y.start;
        });

        int N = intervals.size();
        vector<pair<int,int>> rooms;

        rooms.push_back({intervals[0].start, intervals[0].end});

        for (int i = 1; i < N; ++i) {
            bool findRoom = false;

            for (int j = 0; j < rooms.size(); ++j) {
                int roomStart = rooms[j].first, roomEnd = rooms[j].second;

                if (intervals[i].start >= roomEnd) {
                    findRoom = true;
                    rooms[j].second = intervals[i].end;
                    break;
                }
            }

            if (!findRoom) {
                rooms.push_back({intervals[i].start, intervals[i].end});
            }

            // cout << "Iterate at " << i << endl;
            // for (int i = 0; i < rooms.size(); ++i) {
            //     cout << rooms[i].first << " " << rooms[i].second << endl;
            // }
        }


        return rooms.size();
    }
};
