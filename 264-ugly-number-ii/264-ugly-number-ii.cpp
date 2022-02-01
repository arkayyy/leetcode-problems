class Solution {
public:
    int nthUglyNumber(int n) {
        vector<long long> primes{2,3,5};
        vector<long long> arr(n,-1);
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        pq.push(1);
        long long i = 0;
        
        //we use a priority queue in order to retreive all the elements in ascending fashion
        while(!pq.empty() && arr[n-1]==-1)
        {
            long long top = pq.top();
            pq.pop();
            arr[i++] = top;
            for(auto p:primes) //multiplying current element will all available primes
                pq.push(top*p);
            while(!pq.empty() && pq.top()==top) //removing duplicate elements
                pq.pop();
        }
        
        return arr[n-1];
    }
};