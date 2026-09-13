class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string subset;
        solve (ans, n, 0, subset);
        return ans;
    }

    void solve (vector<string> &ans, int open, int close, string subset) {
        if (open == 0 && close == 0) {
            ans.push_back(subset);
        }

        if (open > 0) {
            subset.append("(");
            solve (ans, open - 1, close + 1, subset);
            subset.pop_back();
        }
        if (close > 0) {
            subset.append(")");
            solve (ans, open, close - 1, subset);
            subset.pop_back();
        }
    }
};
