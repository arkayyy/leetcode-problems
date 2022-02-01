class Solution {
public:
    int nthUglyNumber(int n) {
        
        //---------------APPROACH 1 - TC:O(NK) SC:O(N)-----------------//
//         vector<long long> primes{2,3,5};
//         vector<long long> arr(n,-1);
//         priority_queue<long long, vector<long long>, greater<long long>> pq;
//         pq.push(1);
//         long long i = 0;
        
//         //we use a priority queue in order to retreive all the elements in ascending fashion
//         while(!pq.empty() && arr[n-1]==-1)
//         {
//             long long top = pq.top();
//             pq.pop();
//             arr[i++] = top;
//             for(auto p:primes) //multiplying current element will all available primes
//                 pq.push(top*p);
//             while(!pq.empty() && pq.top()==top) //removing duplicate elements
//                 pq.pop();
//         }
        
//         return arr[n-1];
        
        
        //-----------------APPROACH 2 - DP -  TC: O(N) SC:O(N)--------------//
        vector<int> dp(n);
        dp[0] = 1;
        int p2 = 0, p3 = 0, p5 = 0;
        for(int i = 1; i<n;i++)
        {
            dp[i] = min(dp[p2]*2, min(dp[p3]*3, dp[p5]*5));
            if(dp[i]==dp[p2]*2) p2++;
            if(dp[i]==dp[p3]*3) p3++;
            if(dp[i]==dp[p5]*5) p5++;
        }
        return dp[n-1];
    }
};