class Solution {
public:
    bool isOp(string ch) {
        if (ch == "+" || ch == "-" || ch == "*" || ch == "/") {
            return true;
        }
        return false;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int ans = 0;
        for (auto it: tokens) {
            if (isOp(it)) {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                if (it == "+") {
                    st.push(b + a);
                }
                else if (it == "-") {
                    st.push(b - a);
                }
                else if (it == "*") {
                    st.push(b * a);
                }
                else if (it == "/") {
                    st.push(b / a);
                }
            }
            else {
                st.push(stoi(it));
            }
        }
        return st.top();
    }
};
