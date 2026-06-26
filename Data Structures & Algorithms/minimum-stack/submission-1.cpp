class MinStack {
public:
    vector<int> st;
    vector<int> minVec;
    int curr;

    MinStack() {
        curr = -1;
    }
    
    void push(int val) {
        int mini;
        if(curr != -1) {
            mini = min(val, minVec[curr]);
        }
        else {
            mini = val;
        }

        if (st.size() == curr + 1) {
            st.push_back(val);
            minVec.push_back(mini);
        }
        else {
            st[curr + 1] = val;
            minVec[curr + 1] = mini;
        }
        
        curr++;
    }
    
    void pop() {
        curr--;
    }
    
    int top() {
        return st[curr];
    }
    
    int getMin() {
        return minVec[curr];
    }
};
