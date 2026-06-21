class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int rMax = 0;

        for (int i = prices.size() - 1; i >= 0; i--) {
            if (prices[i] >= rMax) {
                rMax = prices[i];
            }
            else {
                ans = max(ans, rMax - prices[i]);
            }
        }

        return ans;
    }
};
