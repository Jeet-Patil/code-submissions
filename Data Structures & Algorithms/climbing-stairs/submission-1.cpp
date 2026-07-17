class Solution {
public:
    int recur(int n, int curr, vector<int>& dp) {
        if (curr == n) {
            return 1;
        }
        if (curr > n) {
            return 0;
        }

        if (dp[curr] != -1) {
            return dp[curr];
        }

        dp[curr] = recur(n, curr + 1, dp) + recur(n, curr + 2, dp);
        return dp[curr];
    }

    int climbStairs(int n) {
        vector<int> dp(n, -1);
        return recur(n, 0, dp);
    }
};
