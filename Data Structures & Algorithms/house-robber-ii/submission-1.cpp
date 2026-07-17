class Solution {
public:
    int help(vector<int>& nums, int curr, int end, vector<int> &dp) {
        if (curr > end) {
            return 0;
        }
        if (dp[curr] != -1) {
            return dp[curr];
        }

        dp[curr] =  max(help(nums, curr + 1, end, dp), help(nums, curr + 2, end, dp) + nums[curr]);
        return dp[curr];
    }
    int rob(vector<int>& nums) {
        int size = nums.size();
        if (size == 1) {
            return nums[0];
        }
        vector<int> dp1(size, -1);
        vector<int> dp2(size, -1);
        int ans = max(help(nums, 0, size - 2, dp1), help(nums, 1, size - 1, dp2));
        return ans;
    }
};
