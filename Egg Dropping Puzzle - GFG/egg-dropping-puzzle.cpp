// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int util(int eggs, int floors, vector<vector<int>>& dp)
    {
        if(floors == 0 || floors ==1 || eggs ==1) dp[eggs][floors] = floors;
        if(dp[eggs][floors]!=INT_MAX) return dp[eggs][floors];
        for(int i = 1; i<=floors; ++i)
            dp[eggs][floors] = min(dp[eggs][floors], 1+max(util(eggs-1,i-1,dp),util(eggs,floors-i,dp)));
        return dp[eggs][floors];
    }
    int eggDrop(int n, int k) 
    {
        // your code here
        vector<vector<int>> dp(n+1,vector<int>(k+1,INT_MAX));
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