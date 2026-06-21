class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort (nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                break;
            }
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int target = 0 - nums[i];
            int s = i + 1;
            int e = nums.size() - 1;

            while (s < e) {
                int sum = nums[s] + nums[e];
                if (sum < target) {
                    s++;
                }
                else if (sum > target) {
                    e--;
                }
                else {
                    ans.push_back({nums[i], nums[s], nums[e]});
                    s++;
                    e--;
                    while (s < e && nums[s] == nums[s - 1]) {
                        s++;
                    }
                }
            }
        }

        return ans;
    }
};
