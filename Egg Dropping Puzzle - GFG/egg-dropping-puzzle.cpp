// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int util(int n, int k,vector<vector<int>>& dp)
    {
        if(k==1 || n==1 || k==0) dp[n][k] = k; 
        if(dp[n][k]!=-1) return dp[n][k];
        
        int res = INT_MAX;
        for(int i = 1; i<=k;++i)
            res = min(res, 1+max(util(n-1,i-1,dp),util(n,k-i,dp)));
        return dp[n][k] = res==INT_MAX?0:res;
    }
    int eggDrop(int n, int k) 
    {
        // your code here
        vector<vector<int>> dp(n+1, vector<int>(k+1,-1));
        return util(n,k,dp);
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