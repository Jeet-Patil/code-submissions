class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (int i = 0; i < times.size(); i++) {
            adj[times[i][0]].push_back({times[i][2], times[i][1]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int INF = INT_MAX;
        vector<int> dist(n + 1, INF);
        dist[k] = 0;

        pq.push({0, k});
        while (!pq.empty()) {
            auto [time, node] = pq.top();
            pq.pop();
            
            cout << node << " -> ";
            for (auto [timeN, nodeN]: adj[node]) {
                cout << nodeN << " ";
                if (time + timeN < dist[nodeN]) {
                    dist[nodeN] = time + timeN;
                    pq.push({dist[nodeN], nodeN});
                }
            }
            cout << endl;
        }

        int ans = 0;
        for (int i = 1; i < n + 1; i++) {
            if (dist[i] == INF) {
                cout << i << endl;
                return -1;
            }
            ans = max(ans, dist[i]);
        }

        return ans;
    }
};
