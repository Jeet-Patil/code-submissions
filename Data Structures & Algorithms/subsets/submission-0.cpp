class Solution {
public:
    void solve (vector<int>& nums, int it, vector<int> sub, vector<vector<int>>& ans) {
        if (it == nums.size()) {
            ans.push_back(sub);
            return;
        }
        solve (nums, it + 1, sub, ans);
        sub.push_back(nums[it]);
        solve (nums, it + 1, sub, ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> sub;
        solve (nums, 0, sub, ans);
        return ans;
    }
};
