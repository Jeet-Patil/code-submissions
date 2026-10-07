class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<bool> vis(n, 0);
        vector<bool> loop(n, 0);
        vector<vector<int>> adj (n);
        for (auto it: edges) {
            int a = it[0];
            int b = it[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        if (dfs(adj, vis, loop, 0, -1) == false) {
            return false;
        }
        for (int i = 0; i < n; i++) {
            if (vis[i] == 0) {
                return false;
            }
        }
        return true;
    }
    bool dfs(vector<vector<int>> &adj, vector<bool> &vis, vector<bool> &loop, int curr, int par) {
        if (loop[curr] == 1) {
            return false;
        }
        loop[curr] = true;
        vis[curr] = true;

        for (auto it: adj[curr]) {
            if (it != par) {
                if (dfs(adj, vis, loop, it, curr) == false) {
                    return false;
                }
            }
        }
        loop[curr] = false;

        return true;
    }
};
