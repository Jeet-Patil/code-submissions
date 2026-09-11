class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        unordered_map<int, int> count;
        for (int i: nums) {
            count[i]++;
        }
        vector<vector<int>> ans;
        solve(count, ans, nums, {});
        return ans;
    }

    void solve(unordered_map<int, int>& count, vector<vector<int>>& ans, vector<int>& nums, vector<int> temp) {
        if (temp.size() == nums.size()) {
            ans.push_back(temp);
            return;
        }

        for (int i: nums) {
            if (count[i] > 0) {
                temp.push_back(i);
                count[i]--;
                solve(count, ans, nums, temp);
                temp.pop_back();
                count[i]++;
            }
        }
    }
};
