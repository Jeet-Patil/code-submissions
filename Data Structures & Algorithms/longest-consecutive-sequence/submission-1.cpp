class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set <int> s(nums.begin(), nums.end());
        int res = 0;
        for (int num : nums) {
            if (s.find(num - 1) == s.end()) {
                int temp = 0;
                int curr = num;
                while (s.find(curr) != s.end()) {
                    curr++;
                    temp++;
                }
                res = max(res, temp);
            }
        }
        return res;
    }
    // int longestConsecutive(vector<int>& nums) {
    //     unordered_map <int, int> mp;
    //     int res = 0;
    //     for (int num : nums) {
    //         if (!mp[num]) {
    //             mp[num] = mp[num - 1] + mp[num + 1] + 1;
    //             mp[num - mp[num - 1]] = mp[num];
    //             mp[num + mp[num + 1]] = mp[num];
    //             res = max(res, mp[num]);
    //         }
    //     }
    //     return res;
    // }
};
