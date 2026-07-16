class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj (numCourses);
        for (int i = 0; i < prerequisites.size(); i++) {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        vector<bool> pro(numCourses, 0);
        for (int i = 0; i < numCourses; i++) {
            vector<bool> vis(numCourses, 0);
            if (vis[i] == 0) {
                if (findCycle(adj, vis, i, pro) == false) {
                    return false;
                }
            }
        }

        return true;
    }

    bool findCycle(vector<vector<int>>& adj, vector<bool>& vis, int curr, vector<bool>& pro) {
        if (vis[curr] == 1) {
            return false;
        }
        if (pro[curr] == 1) {
            return true;
        }
        vis[curr] = 1;

        for (int i = 0; i < adj[curr].size(); i++) {
            if (findCycle(adj, vis, adj[curr][i], pro) == false) {
                return false;
            }
        }

        pro[curr] = 1;
        vis[curr] = 0;
        return true;
    }
};
