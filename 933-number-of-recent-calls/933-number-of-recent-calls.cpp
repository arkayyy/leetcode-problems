class RecentCounter {
public:
    vector<int> times;
    queue<int> q;
    RecentCounter() {
        times = vector<int>();
        times.reserve(1e4);
    }
    
    int ping(int t) {
        //Vector based soln:-
        // times.push_back(t);
        // int i = times.size()-1;
        // int res = 0;
        // while(i>=0 && (times[i]>=t-3000 && times[i]<=t))
        //     ++res, --i;
        // return res;
        
        //Queue based soln.:-
        q.push(t);
        while(q.front() < t-3000) q.pop(); //we don't care about the previous values and we can discard them, 
        //as the next value is always going to be higher than the highest time in the queue
        return q.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */