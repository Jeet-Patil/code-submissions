class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int mult = 1;
        int cnt0 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                cnt0++;
            }
            else {
                mult = mult * nums[i];
            }
        }
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                if (cnt0 == 1) {
                    ans.push_back(mult);
                }
                else {
                    ans.push_back(0);
                }
            }
            else {
                if (cnt0 >= 1) {
                    ans.push_back(0);
                }
                else {
                    ans.push_back(mult/nums[i]);
                }
            }
        }
        return ans;
    }
};
