class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0]) {
                    bool temp = solve (board, word, i, j, 0);
                    if (temp == true) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool solve (vector<vector<char>>& board, string& word, int i, int j, int it) {
        if (it == word.size()) {
            return true;
        }
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) {
            return false;
        }
        if (board[i][j] != word[it]) {
            return false;
        }
        char temp = board[i][j];
        board[i][j] = '0';
        bool ans = solve (board, word, i + 1, j, it + 1) || 
        solve (board, word, i, j - 1, it + 1) ||
        solve (board, word, i, j + 1, it + 1) ||
        solve (board, word, i - 1, j, it + 1);
        board[i][j] = temp;
        return ans;
    }
};
