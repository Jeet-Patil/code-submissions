class Solution {
public:
    int dfs(vector<int>& coins, int amount, vector<int>& dp) {
        if (amount < 0) {
            return 100000;
        }
        if (amount == 0) {
            return 0;
        }
        if (dp[amount] != -1) {
            return dp[amount];
        }

        int res = 100000;
        for (int i = 0; i < coins.size(); i++) {
            res = min(res, dfs(coins, amount - coins[i], dp));
        }

        dp[amount] = res + 1;
        return res + 1;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
        int ans = dfs(coins, amount, dp);
        if (ans >= 100000) {
            return -1;
        }
        return ans;
    }
};
