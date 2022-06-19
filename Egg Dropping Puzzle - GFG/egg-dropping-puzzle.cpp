// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int dp[201][201];
    int util(int eggs, int floors)
    {
        if(floors==1 || floors == 0 || eggs == 1) return dp[eggs][floors] = floors;
        
        if(dp[eggs][floors]!=-1) return dp[eggs][floors];
        
        int res = INT_MAX;
        for(int i = 1; i<=floors; ++i)
            res = min(1+max(util(eggs-1,i-1),util(eggs,floors-i)),res);
        return dp[eggs][floors] = res;
    }
    int eggDrop(int n, int k) 
    {
        memset(dp,-1,sizeof(dp));
        return util(n,k);
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}
  // } Driver Code Ends