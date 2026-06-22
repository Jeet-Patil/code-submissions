class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int res = 0;
        unordered_map <char, bool> mp;
        for (int r = 0; r < s.size(); r++) {
            if (mp[s[r]] == 0) {
                mp[s[r]] = 1;
                res = max(res, r - l + 1);
            }
            else {
                while (s[l] != s[r]) {
                    mp[s[l]] = 0;
                    l++;
                }
                l++;
                res = max(res, r - l + 1);
            }
        }
        return res;
    }
};
