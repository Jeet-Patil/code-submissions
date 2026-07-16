class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j, int cnt) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == -1) {
            return;
        }
        if (grid[i][j] < cnt) {
            return;
        }
        if (grid[i][j] != 0) {
            grid[i][j] = cnt;
        }
        dfs(grid, i + 1, j, cnt + 1);
        dfs(grid, i - 1, j, cnt + 1);
        dfs(grid, i, j + 1, cnt + 1);
        dfs(grid, i, j - 1, cnt + 1);
    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0) {
                    dfs(grid, i, j, 0);
                }
            }
        }
    }
};
