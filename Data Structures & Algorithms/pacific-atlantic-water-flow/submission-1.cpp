class Solution {
public:
    vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans;
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<bool>> p(n, vector<bool> (m, 0));
        vector<vector<bool>> a(n, vector<bool> (m, 0));

        for (int c = 0; c < m; c++) {
            p[0][c] = 1;
            dfs(heights, p, 0, c);
        }
        for (int r = 0; r < n; r++) {
            p[r][0] = 1;
            dfs(heights, p, r, 0);
        }
        for (int c = 0; c < m; c++) {
            a[n - 1][c] = 1;
            dfs(heights, a, n - 1, c);
        }
        for (int r = 0; r < n; r++) {
            a[r][m - 1] = 1;
            dfs(heights, a, r, m - 1);
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == 1 && p[i][j] == 1) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }

    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& o, int r, int c) {
        for (auto dr: dir) {
            int row = r + dr[0];
            int col = c + dr[1];

            if (row < 0 || row >= heights.size() || col < 0 || col >= heights[0].size()) {
                continue;
            }

            if (o[row][col] == 1) {
                continue;
            }
            if (heights[r][c] <= heights[row][col]) {
                o[row][col] = 1;
                dfs(heights, o, row, col);
            }
        }
    }
};
