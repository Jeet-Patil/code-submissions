class Solution {
public:

    bool row(vector<vector<char>>& board, int r) {
        vector<bool> verify(10, 0);
        for (int i = 0; i < 9; i++) {
            if (board[r][i] == '.') {
                continue;
            }
            int toCheck = board[r][i] - '0';
            if (verify[toCheck] == 1) {
                return 0;
            }
            verify[toCheck] = 1;
        }
        return 1;
    }
    bool col(vector<vector<char>>& board, int c) {
        vector<bool> verify(10, 0);
        for (int i = 0; i < 9; i++) {
            if (board[i][c] == '.') {
                continue;
            }
            int toCheck = board[i][c] - '0';
            if (verify[toCheck] == 1) {
                return 0;
            }
            verify[toCheck] = 1;
        }
        return 1;
    }
    bool box(vector<vector<char>>& board, int r, int c) {
        vector<bool> verify(10, 0);
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[r+i][c+j] == '.') {
                    continue;
                }
                int toCheck = board[r+i][c+j] - '0';
                if (verify[toCheck] == 1) {
                    return 0;
                }
                verify[toCheck] = 1;
            }
        }
        return 1;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            bool check = row(board, i);
            if (check == 0) {
                return 0;
            }
            check = col(board, i);
            if (check == 0) {
                return 0;
            }
        }

        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                bool check = box(board, i, j);
                if (check == 0) {
                    return 0;
                }
            }
        }

        return 1;
    }
};
