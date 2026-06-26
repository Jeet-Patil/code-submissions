class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char ch: s) {
            st.push(ch);
            bool flag = 1;
            while (flag == 1) {
                flag = 0;
                if (st.size() >= 2) {
                    char a = st.top();
                    st.pop();
                    char b = st.top();
                    st.pop();
                    if ((a == ')' && b == '(') || 
                        (a == ']' && b == '[') || 
                        (a == '}' && b == '{')) {
                        flag = 1;
                    }
                    else {
                        st.push(b);
                        st.push(a);
                    }
                }
            }
        }
        if (st.empty()) {
            return true;
        }
        return false;
    }
};
