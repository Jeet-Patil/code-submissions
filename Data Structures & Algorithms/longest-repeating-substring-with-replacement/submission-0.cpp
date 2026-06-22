class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int res = 0;
        char maxi = 'A';
        unordered_map <char, int> mp;
        for (int r = 0; r < s.size(); r++) {
            mp[s[r]]++;
            if (mp[maxi] < mp[s[r]]) {
                maxi = s[r];
            }
            int sz = r - l + 1;
            if (k + mp[maxi] < sz) {
                mp[s[l]]--;
                l++;
                if (s[l] == maxi) {
                    int temp = 0;
                    for (int i = l; i <= r; i++) {
                        if (mp[s[i]] > temp) {
                            temp = mp[s[i]];
                            maxi = s[i];
                        }
                    }
                }
            }
            else {
                res = max(res, sz);
            }
        }
        return res;
    }
};
