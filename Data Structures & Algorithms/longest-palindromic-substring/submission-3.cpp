class Solution {
public:
    string longestPalindrome(string s) {
        string ans;
        int maxLen = 0;
        for (int i = 0; i < s.size(); i++) {
            int l = i;
            int r = i;
            while (l >= 0 && r <= s.size() - 1) {
                if (s[l] == s[r]) {
                    if (maxLen < r - l + 1) {
                        maxLen = r - l + 1;
                        ans = s.substr(l, r - l + 1);
                    }
                    l--;
                    r++;
                }
                else {
                    break;
                }
            }
        }
        for (int i = 0; i < s.size() - 1; i++) {
            int l = i;
            int r = i + 1;
            while (l >= 0 && r <= s.size() - 1) {
                if (s[l] == s[r]) {
                    if (maxLen < r - l + 1) {
                        maxLen = r - l + 1;
                        ans = s.substr(l, r - l + 1);
                    }
                    l--;
                    r++;
                }
                else {
                    break;
                }
            }
        }
        return ans;
    }
};
