class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto loc = lower_bound(nums.begin(), nums.end(), target);
        if (loc != nums.end() && *loc == target) {
            return loc - nums.begin();
        }
        return -1;
    }
};
