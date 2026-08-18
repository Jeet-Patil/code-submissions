class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars;
        
        int size = speed.size();
        for (int i = 0; i < size; i++) {
            cars.push_back({position[i], speed[i]});
        }

        sort(cars.begin(), cars.end(), [](auto &a, auto &b) {
            return a.first > b.first;
        });

        int fleet = 0;
        double timeCap = 0;

        for (auto &[pos, spd]: cars) {
            double time = (double)(target - pos) / spd;
            
            if (time > timeCap) {
                fleet++;
                timeCap = time;
            }
        }
        
        return fleet;
    }
};
