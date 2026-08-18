class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int size = speed.size();
        unordered_map<double, int> mp;
        vector<pair<int, int>> vec;
        int ans = 0;
        for (int i = 0; i < size; i++) {
            vec.push_back({position[i], speed[i]});
        }
        sort(vec.begin(), vec.end(), [](pair<int, int> a, pair<int, int>b) {
            return a.first > b.first;
        });
        double timeCap = 0;
        for (int i = 0; i < size; i++) {
            double pos = vec[i].first;
            double spd = vec[i].second;
            double time = (target - pos) / spd;
            time = max(timeCap, time);
            if (mp.count(time) == 0) {
                ans++;
            }
            mp[time]++;
            timeCap = max(timeCap, time);
        }
        return ans;
    }
};
