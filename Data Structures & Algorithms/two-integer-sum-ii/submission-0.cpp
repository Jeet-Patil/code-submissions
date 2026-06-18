class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map <int, int> mp;
        for (int i = 0; i < numbers.size(); i++) {
            int num = numbers[i];
            int chk = target - num;
            if (mp[chk]) {
                return {mp[chk], i + 1};
            }
            mp[num] = i + 1;
        }
        return {};
    }
};
