class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int mult = 1;
        vector<int> ans(nums.size(), 1);

        for (int i = 1; i < nums.size(); i++) {
            mult *= nums[i - 1];
            ans[i] = mult;
        }

        mult = 1;
        for (int i = nums.size() - 2; i >= 0; i--) {
            mult *= nums[i + 1];
            ans[i] *= mult;
        }

        return ans;
    }
};
