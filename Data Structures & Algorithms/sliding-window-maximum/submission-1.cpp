class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<pair<int, int>> temp;
        for (int i = 0; i < nums.size(); i++) {
            pair <int, int> a = {nums[i], i};
            temp.push_back(a);
        }
        sort(temp.begin(), temp.end(), [] (pair <int, int> a, pair <int, int> b) {
            return a.first > b.first;
        });
        int cnt = 0;
        int sz = nums.size() - k + 1;
        vector<int> ans (sz, -10001);
        for (auto it: temp) {
            int val = it.first;
            int loc = it.second - k + 1;
            int i = 0;
            while (i != k) {
                if (loc + i >= sz) {
                    break;
                }
                if (loc + i < 0 || ans[loc + i] != -10001) {
                    i++;
                    continue;
                }
                ans[loc + i] = val;
                cnt++;
                i++;
            }
            if (cnt == sz) {
                break;
            }
        }
        return ans;
    }
};
