class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        for (int i = 0; i < k - 1; i++) {
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        for (int i = k - 1; i < nums.size(); i++) {
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
            while (dq.front() + k <= i){
                dq.pop_front();
            }
            ans.push_back(nums[dq.front()]);
        }
        return ans;
        
        
        // priority_queue<pair<int, int>> pq;
        // vector<int> ans;
        // for (int i = 0; i < k - 1; i++) {
        //     pq.push({nums[i], i});
        // }
        // for (int i = k - 1; i < nums.size(); i++) {
        //     pq.push({nums[i], i});
        //     while (pq.top().second <= i - k) {
        //         pq.pop();
        //     }
        //     ans.push_back(pq.top().first);
        // }
        // return ans;
    }
};
