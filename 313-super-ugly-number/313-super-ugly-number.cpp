class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        
        //---------TLE  --- APPROACH - 1: PRIORITY QUEUE TC: O(NK) SC: O(N) ---------//
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
        
        
        //--------------APPROACH - 2: DP APPROACH TC:O(NK) SC:O(N+K) ----------------------//
        //use long long otherwise will result in TLE
        vector<long long> dp(n);
        dp[0] = 1;
        
        //same as UGLY NUMBERS (264), except the fact that we use individual pointers for all primes given in primes[] here
        vector<long long> pointers(primes.size());
        
        for(long long i = 1; i<n;i++)
        {
            long long mini = LLONG_MAX;
            for(long long j = 0;j<primes.size(); j++)
            {
                mini = min(mini, dp[pointers[j]]*primes[j]);
            }
            dp[i] = mini;
            for(long long j = 0; j<primes.size(); j++)
            {
                if(mini ==  dp[pointers[j]]*primes[j])
                    pointers[j]++;
            }
        }
        
        return dp[n-1];
    }
};