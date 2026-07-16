class Solution {
public:

    void mark (vector<vector<char>>& grid, vector<vector<bool>>& vis, int i, int j) {
        cout << " " << i << " " << j << endl;
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) {
            return;
        }
        if (vis[i][j] == 1 || grid[i][j] == '0') {
            return;
        }

        vis[i][j] = 1;
        mark(grid, vis, i + 1, j);
        mark(grid, vis, i - 1, j);
        mark(grid, vis, i, j + 1);
        mark(grid, vis, i, j - 1);
    }

    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        cout << "Start " << endl;
        vector<vector<bool>> vis(grid.size(), vector<bool> (grid[0].size(), 0));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                cout << i << " " << j << endl;
                if (vis[i][j] == 0 && grid[i][j] == '1') {
                    mark(grid, vis, i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
};
