class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        
        for(auto s: stones) pq.push(s);
        while(!pq.empty())
        {
            int t1 = pq.top(); pq.pop();
            if(pq.empty()) return t1;
            int t2 = pq.top(); pq.pop();
            if(t1!=t2) pq.push(t1-t2);
        }
        
        return 0;
    }
};