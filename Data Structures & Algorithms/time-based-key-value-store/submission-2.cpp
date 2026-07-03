class TimeMap {
public:
    unordered_map <string,vector<pair<string, int>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({value, timestamp});
        return;
    }
    
    string get(string key, int timestamp) {
        if (mp.count(key) == 0) {
            return "";
        }
        vector<pair<string,int>> vec = mp[key];
        int s = 0;
        int e = vec.size() - 1;
        int ans = 0;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            string val = vec[mid].first;
            int tp = vec[mid].second;
            if (tp == timestamp) {
                return val;
            }
            else if (tp > timestamp) {
                e = mid - 1;
            }
            else {
                ans = max(ans, mid);
                s = mid + 1;
            }
        }
        if (vec[ans].second > timestamp) {
            return "";
        }
        return vec[ans].first;
    }
};
