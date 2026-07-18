class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int amt = 1; amt <= amount; amt++) {
            for (int coin = 0; coin < coins.size(); coin++) {
                if (amt >= coins[coin]) {
                    dp[amt] = min(dp[amt], dp[amt - coins[coin]] + 1);
                }
            }
        }
        if (dp[amount] == amount + 1) {
            return -1;
        }
        return dp[amount];
    }
};
