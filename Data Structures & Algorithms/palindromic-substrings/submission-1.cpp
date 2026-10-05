class Solution {
public:
    int countSubstrings(string s) {
        int ans = 0;
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        for (int i = s.size() - 1; i >= 0; i--) {
            for (int j = i; j < s.size(); j++) {
                int st = i;
                int ed = j;
                if (s[st] == s[ed]) {
                    if (j - i <= 2 || dp[i + 1][j - 1]) {
                        ans++;
                        dp[i][j] = true;
                    }
                }
            }
        }
        return ans;
    }
};