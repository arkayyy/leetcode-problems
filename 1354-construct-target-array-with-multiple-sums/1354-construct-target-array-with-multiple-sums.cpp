class Solution {
public:
   
    bool isPossible(vector<int>& target) {
        priority_queue<int> pq;
        long long sum = 0;
        for(auto num : target){
            pq.push(num);
            sum+=num;
        }
        while(pq.top() != 1){
            int t= pq.top(); pq.pop();
            sum-=t;
            if(sum == 0 || sum >= t) return false;
            t%=sum;
            sum+=t;
            pq.push(t?t:sum);
        }
        return true;
    }
};