class Solution {
public:
    static bool lessThan(pair<int, int>& i, pair<int, int>& j) {
        return i.first > j.first;
    }
    double time(int target, pair<int, int> pt) {
        return ((double)target - pt.first) / pt.second;
    }
    int carFleet(int target, vector<int>& position, vector<int>& speed) {       
        vector<pair<int, int>> vt;

        int N = position.size();

        for (int i = 0; i < N; ++i) {
            vt.push_back(make_pair(position[i], speed[i]));
        }

        sort(vt.begin(), vt.end(), lessThan);

        // for (int i = 0; i < N; ++i) {
        //     cout << vt[i].first << " " << vt[i].second << endl;
        // }
        int carFleet = 1;
        double maxTime = time(target, vt[0]);

        // cout << maxTime << endl;
        for (int i = 1; i < N; ++i) {
            double currentTime = time(target, vt[i]);

            // cout << currentTime << endl;

            if (currentTime > maxTime) {
                maxTime = currentTime;
                carFleet++;
            }
        }
        
        return carFleet;
    }
};
