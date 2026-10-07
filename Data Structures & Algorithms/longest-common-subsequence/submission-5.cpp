class Solution {
public:
    int solve(string text1, string text2, int i, int j, vector<vector<int>> &dp) {
        if (i >= text1.size() || j >= text2.size()) {
            return 0;
        }
        
        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        if (text1[i] == text2[j]) {
            int ans = solve(text1, text2, i + 1, j + 1, dp) + 1;
            dp[i][j] = ans;
            return ans;
        }

        int ans1 = 0;
        int ans2 = 0;
        ans1 = solve(text1, text2, i + 1, j, dp);
        ans2 = solve(text1, text2, i, j + 1, dp);
        dp[i][j] = max(ans1, ans2);
        return dp[i][j];
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>>dp (n, vector<int> (m, -1));       
        return solve(text1, text2, 0, 0, dp);
    }
};
