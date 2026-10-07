class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size = nums.size();
        int goal = size - 1;

        for (int i = size - 2; i >= 0; i--) {
            if (i + nums[i] >= goal) {
                goal = i;
            }
        }

        return goal == 0 ? true : false;
    }
};
