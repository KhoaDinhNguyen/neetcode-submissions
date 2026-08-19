class Solution {
public:
    unordered_map<int, int> meetingToRoom;
    unordered_map<int, int> used;
    int mostBooked(int n, vector<vector<int>>& meetings) {
        if (n == 1) return 0;

        priority_queue<int, vector<int>, greater<int>> availableRoom;

        for (int i = 0; i < n; ++i) availableRoom.push(i);

        // pair<meetingId, end>

        auto compare = [](pair<int, int>& i, pair<int, int>& j) {
            return i.second > j.second;
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)> duringMeetings;

        queue<pair<int, int>> delayedMeetings;

        sort(meetings.begin(), meetings.end(), [](vector<int>& i, vector<int>& j) {
            return i[0] < j[0];
        });

        int numOfMeeting = 0, N = meetings.size(), t = 1, i = 0;

        while (numOfMeeting < N) {
            // case 1: has delay meeting
            while (!delayedMeetings.empty() && !availableRoom.empty()) {
                int meetingId = delayedMeetings.front().first;
                delayedMeetings.pop();
                int room = availableRoom.top();
                availableRoom.pop();

                used[room]++;
                meetingToRoom[meetingId] = room;
                duringMeetings.push({meetingId, meetings[meetingId][1] + t - meetings[meetingId][0]});
                numOfMeeting++;
            } 

            // case 2: no delay meeting and t reaches start time
            if (i < N && meetings[i][0] <= t) {
                if (!availableRoom.empty()) {
                    int room = availableRoom.top();
                    availableRoom.pop();
                    used[room]++;
                    meetingToRoom[i] = room;
                    duringMeetings.push({i, meetings[i][1]});
                    numOfMeeting++;
                }
                else {
                    delayedMeetings.push({i, meetings[i][1]});
                }
                i++;
            }

            // case 3: meeting ends
            while (!duringMeetings.empty() && duringMeetings.top().second - 1 <= t) {
                // return the room
                int meetingId = duringMeetings.top().first;
                duringMeetings.pop();

                int room = meetingToRoom[meetingId];
                availableRoom.push(room);
            }
            t++;
        }

        int maxUsed = 0, ans = 0;

        auto it = used.begin();

        while (it != used.end()) {
            // cout << it->first << " " << it->second << endl;
            if (it->second > maxUsed) {
                ans = it->first;
                maxUsed = it->second;
            }
            else if (it->second >= maxUsed && it->first < ans) {
                ans = it->first;
            }
            it++;
        }

        return ans;
    }
};