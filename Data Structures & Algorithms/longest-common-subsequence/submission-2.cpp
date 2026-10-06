class Solution {
public:
vector<vector<int>>dp;
    int solve(string text1, string text2, int i, int j) {
        if (i >= text1.size() || j >= text2.size()) {
            return 0;
        }
        
        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        if (text1[i] == text2[j]) {
            int ans = solve(text1, text2, i + 1, j + 1) + 1;
            dp[i][j] = ans;
            // cout << "=";
            // cout << text1[i] << " " << text2[j] << " ";
            // cout << ans << endl;
            return ans;
        }

        int ans1 = 0;
        int ans2 = 0;
        ans1 = solve(text1, text2, i + 1, j);
        ans2 = solve(text1, text2, i, j + 1);
        // cout << text1[i] << " " << text2[j] << " ";
        // cout << ans1 << endl;
        // cout << ans2 << endl;
        dp[i][j] = max(ans1, ans2);
        return dp[i][j];
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        dp.assign(n + 1,vector<int> (m + 1,-1));       
        return solve(text1, text2, 0, 0);
    }
};
