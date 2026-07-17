class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int sz = cost.size();
        int c = 0;
        int a = cost[0];
        int b = cost[1];
        for (int i = 2; i < sz; i++) {
            c = min(b, a) + cost[i];
            a = b;
            b = c;
        }

        return min(b, a);
    }
};
