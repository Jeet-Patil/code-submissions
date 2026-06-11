class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> st;
        for (int i = 0; i < nums.size(); i++) {
            st.insert(nums[i]);
            if (st.size() != i + 1) {
                return true;
            }
        }
        return false;
    }
};