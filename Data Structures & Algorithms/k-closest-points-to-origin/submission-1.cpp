class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for (int i = 0; i < points.size(); i++) {
            int a = points[i][0];
            int b = points[i][1];
            pq.push({(a*a) + (b*b), i});
        }
        vector<vector<int>> ans;
        for (int i = 0; i < k; i++) {
            int loc = pq.top().second;
            pq.pop();
            ans.push_back(points[loc]);
        }
        return ans;
    }
};
