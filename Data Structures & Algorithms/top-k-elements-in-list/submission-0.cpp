class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int, int> mp;
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }

        for (int i = 0; i < k; i++) {
            int maxi = 0;
            for (auto& it: mp) {
                if (mp[maxi] < it.second) {
                    maxi = it.first;
                }
            }
            mp[maxi] = 0;
            ans.push_back(maxi);
        }

        return ans;
    }
};