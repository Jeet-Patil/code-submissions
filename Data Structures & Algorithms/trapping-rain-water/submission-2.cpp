class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        bool start = 0;
        int dist = 0;
        int blocks = 0;

        vector<int> post (height.size(), 0);
        post[height.size() - 1] = 0;
        for (int i = height.size() - 2; i >= 0; i--) {
            post[i] = max(post[i + 1], height[i + 1]);
        }

        int currHt = min(height[0], post[0]);
        for (int i = 1; i < height.size(); i++) {
            if (height[i] >= currHt) {
                ans += (currHt * dist) - blocks;
                blocks = 0;
                dist = 0;
                // while (i < height.size() && height[i] > post[i]) {
                //     i++;
                // }
                // if (i >= height.size()) {
                //     break;
                // }
                currHt = min(height[i], post[i]);
                continue;
            }
            else {
                blocks += height[i];
                dist++;
            }
        }
        return ans;
    }
};
