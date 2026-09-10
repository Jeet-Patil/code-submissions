class Solution {
public:
    void solve(vector<int>& nums, int target, int it, vector<vector<int>>& res, vector<int> sub) {
        if (target == 0) {
            res.push_back(sub);
            return;
        }
        if (it >= nums.size()) {
            return;
        }
        if (target >= nums[it]) {
            sub.push_back(nums[it]);
            solve (nums, target - nums[it], it, res, sub);
            sub.pop_back();
            solve (nums, target, it + 1, res, sub);
        }
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> sub;
        sort(nums.begin(), nums.end());
        solve (nums, target, 0, res, sub);
        return res;
    }
};
