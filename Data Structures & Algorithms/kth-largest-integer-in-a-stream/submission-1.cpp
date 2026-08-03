class KthLargest {
public:
    int check = 0;
    priority_queue<int, vector<int>, greater<int>> pq;

    KthLargest(int k, vector<int>& nums) {
        check = k;
        for (int it: nums) {
            pq.push(it);
            if (pq.size() > check) {
                pq.pop();
            }
        }
    }
    
    int add(int val) {
        pq.push(val);
        if (pq.size() > check) {
            pq.pop();
        }
        return pq.top();
    }
};
