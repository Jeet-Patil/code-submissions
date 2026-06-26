class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int size = temperatures.size();
        stack<int> st;
        vector<int> ans (size, 0);
        st.push(size - 1);
        for (int i = size - 2; i >= 0; i--) {
            while (!st.empty() && temperatures[st.top()] <= temperatures[i]) {
                st.pop();
            }
            if (st.empty()) {
                st.push(i);
            }
            else {
                ans[i] = st.top() - i;
                st.push(i);
            }
        }
        return ans;
    }
};
