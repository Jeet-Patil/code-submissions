class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = -10001;
        int temp = -10001;
        for (int i = 0; i < nums.size(); i++) {
            temp = max(nums[i], temp + nums[i]);
            ans = max(temp, ans);
        }
        return ans;
    }
};
