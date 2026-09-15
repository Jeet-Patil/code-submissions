class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) {
            return {};
        }
        vector<string> phone = {" ", "00", "abc", "def","ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        vector<string> ans;
        solve (phone, digits, ans, 0, "");
        return ans;
    }

    void solve (vector<string>& phone, string& digits, vector<string>& ans, int it, string temp) {
        if (it == digits.size()) {
            ans.push_back(temp);
            return;
        }

        string curr = phone[digits[it] - '0'];
        for (char ch: curr) {
            temp.push_back(ch);
            solve (phone, digits, ans, it + 1, temp);
            temp.pop_back();
        }
    }
};
