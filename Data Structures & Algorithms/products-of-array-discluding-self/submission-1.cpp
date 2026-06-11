class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int mult = 1;
        vector<int> pre(nums.size(), 1);
        vector<int> suff(nums.size(), 1);

        for (int i = 1; i < nums.size(); i++) {
            mult *= nums[i - 1];
            pre[i] = mult;
        }

        mult = 1;
        for (int i = nums.size() - 2; i >= 0; i--) {
            mult *= nums[i + 1];
            suff[i] = mult;
        }

        vector<int> ans(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++) {
            ans[i] = pre[i] * suff[i];
        }

        return ans;
    }
};
