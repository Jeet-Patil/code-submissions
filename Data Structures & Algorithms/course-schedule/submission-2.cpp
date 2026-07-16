class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj (numCourses);
        for (int i = 0; i < prerequisites.size(); i++) {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        vector<int> state(numCourses, 0);
        for (int i = 0; i < numCourses; i++) {
            if (state[i] != 3) {
                if (findCycle(adj, state, i) == false) {
                    return false;
                }
            }
        }

        return true;
    }

    bool findCycle(vector<vector<int>>& adj, vector<int>& state, int curr) {
        if (state[curr] == 1) {
            return false;
        }
        if (state[curr] == 2) {
            return true;
        }
        state[curr] = 1;

        for (int i = 0; i < adj[curr].size(); i++) {
            if (findCycle(adj, state, adj[curr][i]) == false) {
                return false;
            }
        }

        state[curr] = 2;
        return true;
    }
};
