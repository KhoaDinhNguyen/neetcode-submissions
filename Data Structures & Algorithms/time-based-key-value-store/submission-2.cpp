class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> mp;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back(make_pair(timestamp, value));
    }
    
    string get(string key, int timestamp) {
        if (mp[key].size() == 0) return "";

        vector<pair<int, string>> values = mp[key];

        int l = 0, r = values.size() - 1;
        // cout << "Before: " << l << endl;
        while (l < r - 1) {
            int mid = l + (r - l) / 2;
            // cout << mid << endl;
            if (values[mid].first == timestamp) return values[mid].second;
            else if (values[mid].first > timestamp) r = mid - 1;
            else l = mid;
        }
        
        int ans = l + 1 < values.size() && values[l + 1].first <= timestamp? l + 1: l;

        // cout << "After: " << ans << endl;
        return values[ans].first <= timestamp? values[ans].second: "";
    }
};
