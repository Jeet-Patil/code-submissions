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
        // for (int j = 0; j < temp.size(); j++) {
        //     cout << temp[j].first << temp[j].second << " ";
        // }
        // cout << endl;
        int sz = nums.size() - k + 1;
        vector<int> ans (sz, -10001);
        for (auto it: temp) {
            int val = it.first;
            int loc = it.second - k + 1;
            int i = 0;
            // cout << val << " " << loc << endl;
            while (i != k) {
                // cout << i << ": " << loc + i << endl;
                if (loc + i >= sz) {
                    // cout << "1!!!!" << loc + i << sz << endl;
                    break;
                }
                if (loc + i < 0 || ans[loc + i] != -10001) {
                    i++;
                    // cout << "2!!!!" << endl;
                    continue;
                }
                ans[loc + i] = val;
                i++;
                // for (int j = 0; j < sz; j++) {
                //     cout << ans[j] << " ";
                // }
                // cout << endl;
            }
        }
        return ans;
    }
};
