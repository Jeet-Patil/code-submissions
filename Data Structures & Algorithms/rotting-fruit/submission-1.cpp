class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int cnt = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
                if (grid[i][j] == 1) {
                    cnt++;
                }
            }
        }
        vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int ans = 0;
        while(!q.empty() && cnt > 0) {
            int size = q.size();
            while (size--) {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int r = row + dir[i][0];
                    int c = col + dir[i][1];

                    if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] != 1) {
                        continue;
                    }

                    grid[r][c] = 2;
                    q.push({r, c});
                    cnt--;
                }
            }
            ans++;
        }

        if (cnt != 0) {
            return -1;
        }
        return ans;
    }
};
