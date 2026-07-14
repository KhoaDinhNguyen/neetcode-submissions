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
        string res = "";

        while (l <= r) {
            int mid = l + (r - l) / 2;

            // Largest lesser
            if (values[mid].first <= timestamp) {
                res = values[mid].second;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        
        return res;
    }
};
