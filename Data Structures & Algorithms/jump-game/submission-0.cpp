class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<bool> possible (nums.size(), 0);
        possible[0] = 1;

        for (int i = 0; i < nums.size(); i++) {
            // cout << nums[i] << " -> ";
            // for (int i = 0; i < nums.size(); i++) {
            //     cout << possible[i] << " ";
            // }
            // cout << endl;
            if (possible[i] == 1) {
                for (int j = 0; j < nums[i] && j < nums.size(); j++) {
                    possible[i + j + 1] = 1;
                }
            }
        }

        // for (int i = 0; i < nums.size(); i++) {
        //     cout << possible[i] << " ";
        // }
        
        return possible[nums.size() - 1];
    }
};
