class RecentCounter {
public:
    vector<int> times;
    RecentCounter() {
        times = vector<int>();
        times.reserve(1e4);
    }
    
    int ping(int t) {
        times.push_back(t);
        int i = times.size()-1;
        int res = 0;
        while(i>=0 && (times[i]>=t-3000 && times[i]<=t))
            ++res, --i;
        return res;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */