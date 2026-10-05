class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp (s.size(), -1);
        return dfs (0, s, dp);
    }

    int dfs(int i, string s, vector<int>& dp) {
        if (i == s.size()) {
            return 1;
        }
        if (s[i] == '0') {
            return 0;
        }
        if (dp[i] != -1) {
            return dp[i];
        }

        int ans = dfs (i + 1, s, dp);
        if (i < s.size() - 1 && (s[i] == '1' || (s[i] == '2' && s[i + 1] < '7'))) {
            ans += dfs (i + 2, s, dp);
        }

        dp[i] = ans;
        return ans;
    }
};
