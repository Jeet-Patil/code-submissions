class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int size = heights.size();
        stack<int> minL;
        stack<int> minR;
        vector<int> left(size, 0);
        vector<int> right(size, 0);
        for (int i = 0; i < size; i++) {
            int curr = heights[i];
            if (minL.empty()) {
                minL.push(i);
                left[i] = 0;
            }
            else {
                while (!minL.empty() && heights[minL.top()] >= curr) {
                    minL.pop();
                }
                if (minL.empty()) {
                    minL.push(i);
                    left[i] = 0;
                }
                else {
                    left[i] = minL.top() + 1;
                    minL.push(i);
                }
            }
            int locR = size - 1 - i;
            int currR = heights[locR];
            if (minR.empty()) {
                minR.push(locR);
                right[locR] = size - 1;
            }
            else {
                while (!minR.empty() && heights[minR.top()] >= currR) {
                    minR.pop();
                }
                if (minR.empty()) {
                    minR.push(locR);
                    right[locR] = size - 1;
                }
                else {
                    right[locR] = minR.top() - 1;
                    minR.push(locR);
                }
            }
        }
        // for (int i = 0; i < size; i++) {
        //     cout << left[i] << " ";
        // }
        // cout << endl;
        // for (int i = 0; i < size; i++) {
        //     cout << right[i] << " ";
        // }
        // cout << endl;
        int ans = 0;
        for (int i = 0; i < size; i++) {
            int width = right[i] - left[i] + 1;
            int area = width * heights[i];
            ans = max(area, ans);
        }
        return ans;
    }
};
