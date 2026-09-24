class Solution {
public:
    bool check (int r, int c, int n, vector<bool>& col, vector<string>& temp) {
        if (col[c]) {
            return false;
        }
        
        int tr = r;
        int tc = c;
        while (tr >= 0 && tc < n) {
            if (temp[tr][tc] == 'Q') {
                return false;
            }
            tr--;
            tc++;
        }
        
        tc = c;
        tr = r;
        while (tr >= 0 && tc >= 0) {
            if (temp[tr][tc] == 'Q') {
                return false;
            }
            tr--;
            tc--;
        }
        
        return true;
    }

    void place (int r, int n, vector<bool>& col, vector<vector<string>>& ans, vector<string>& temp) {
        if (r == n) {
            ans.push_back(temp);
            return;
        }
        
        for (int i = 0; i < n; i++) {
            if (check(r, i, n, col, temp)) {
                temp[r][i] = 'Q';
                col[i] = true;
                
                place(r + 1, n, col, ans, temp);
                
                temp[r][i] = '.';
                col[i] = false;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<bool> col(n, false);
        
        vector<string> temp(n, string(n, '.'));
        vector<vector<string>> ans;
        
        place(0, n, col, ans, temp);
        
        return ans;
    }
};