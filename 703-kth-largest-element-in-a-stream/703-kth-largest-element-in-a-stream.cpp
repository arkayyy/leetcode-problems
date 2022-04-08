class KthLargest {
    priority_queue<int, vector<int>, greater<int>> pq;
    int kk = 0;
public:
    
    KthLargest(int k, vector<int>& nums) {
        kk = k;
        for(auto n: nums)
        {
        pq.push(n); 
        if(pq.size()>kk) 
            pq.pop(); //smallest no. getting popped.
        }
        //here we end up with the k greatest elements in the priority queue left
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>kk) pq.pop(); //popping the smallest element, to be left over with only the k greatest elements
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */