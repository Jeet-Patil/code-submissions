class Solution {
public:
    int maxArea(vector<int>& heights) {
        int s = 0;
        int e = heights.size() - 1;
        int ans = 0;
        while (s < e) {
            cout << heights[s] << " " << heights[e] << endl;
            int temp = (e - s) * min(heights[s], heights[e]);
            ans = max(temp, ans);
            if (heights[e] < heights[s]) {
                e--;
            }
            else {
                s++;
            }
        }
        return ans;
    }
};
