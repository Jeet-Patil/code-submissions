class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size = nums.size();
        vector<bool> possible (size, 0);
        possible[size - 1] = 1;

        for (int i = size - 2; i >= 0; i--) {
            for (int j = i + 1; j < size && j < nums[i] + i + 1; j++) {
                if (possible[j] == 1){
                    possible[i] = 1;
                    break;
                }
            }
        }

        return possible[0];
    }
};
