class Solution {
public:

    // void fun (vector<int>& nums, vector<vector<int>>& ans, int s, int e, int target, int i) {
    //     if (s >= e) {
    //         return;
    //     }
    //     int sum = nums[s] + nums[e];
    //     if (sum < target) {
    //         fun (nums, ans, s + 1, e, target, i);
    //     }
    //     else if (sum > target) {
    //         fun (nums, ans, s, e + 1, target, i);
    //     }
    //     else {
    //         ans.push_back({nums[i], nums[s], nums[e]});
    //         fun (nums, ans, s + 1, e, target, i);
    //         fun (nums, ans, s, e + 1, target, i);
    //     }
    // }

    vector<vector<int>> threeSum(vector<int>& nums) {
        sort (nums.begin(), nums.end());
        set<vector<int>> ans;
        for (int i = 0; i < nums.size(); i++) {
            int target = 0 - nums[i];
            int s = i + 1;
            int e = nums.size() - 1;
            // fun (nums, ans, s, e, target, i);
            while (s < e) {
                int sum = nums[s] + nums[e];
                if (sum < target) {
                    s++;
                }
                else if (sum > target) {
                    e--;
                }
                else {
                    ans.insert({nums[i], nums[s], nums[e]});
                    s++;
                }
            }
        }

        vector<vector<int>> res;
        for (auto it: ans) {
            res.push_back(it);
        }
        return res;
    }
};
