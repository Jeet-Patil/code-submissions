class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = 0;
        for (int i = 0; i < piles.size(); i++) {
            maxi = max (maxi, piles[i]);
        }
        int s = 1;
        int e = maxi;
        int ans = maxi;
        while (s <= e) {
            int mid = ((e-s) / 2) + s;
            long long check = 0;
            for (int i = 0; i < piles.size(); i++) {
                check += ceil(((double)piles[i] / mid));
            }
            cout << mid << " " << check << endl;
            if (check <= h) {
                ans = min(ans, mid);
                e = mid - 1;
            }
            else {
                s = mid + 1;
            }
        }
        return ans;
    }
};
