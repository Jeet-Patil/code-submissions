class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int, int>> que;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0) {
                    que.push({i, j});
                }
            }
        }

        vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while (!que.empty()) {
            int row = que.front().first;
            int col = que.front().second;
            que.pop();
            
            for (int i = 0; i < 4; i++) {
                int r = row + dir[i][0];
                int c = col + dir[i][1];

                if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] != 2147483647) {
                    continue;
                }
                grid[r][c] = grid[row][col] + 1;
                que.push({r, c});
            }
        }
    }

};
