class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map <string, vector<int>> mp;
        for (int i = 0; i < strs.size(); i++) {
            string curr = strs[i];
            sort(curr.begin(), curr.end());

            if (mp.find(curr) != mp.end()) {
                mp[curr].push_back(i);
            }
            else {
                mp[curr] = {i};
            }
        }

        for (auto it: mp) {
            vector<string> temp;
            for (int i = 0; i < it.second.size(); i++) {
                temp.push_back(strs[it.second[i]]);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};