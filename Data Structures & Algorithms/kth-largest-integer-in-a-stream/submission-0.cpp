class KthLargest {
public:
    int check = 0;
    priority_queue<int> pq;

    KthLargest(int k, vector<int>& nums) {
        check = k;
        for (int it: nums) {
            pq.push(it);
        }
    }
    
    int add(int val) {
        pq.push(val);
        return findK(pq, check);
    }

    int findK (priority_queue<int> pq, int check) {
        for (int i = 0; i < check - 1; i++) {
            pq.pop();
        }
        return pq.top();
    }
};
