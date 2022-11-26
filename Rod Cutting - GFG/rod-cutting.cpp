//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int recur(int price[], int n, vector<int>&dp)
    {
        if(n==0) return 0;
        if(dp[n]!=-1) return dp[n];
        int res = INT_MIN;
        for(int i = 1; i<=n; ++i)
        {
            res = max(res,price[i-1]+recur(price,n-i,dp));
        }
        return dp[n]=res;
    }
    int cutRod(int price[], int n) {
        //code here
        //vector<int> dp(n+1,-1);
        //return recur(price,n,dp);
        
        //Tabulation:-
        vector<int> dp(n+1,INT_MIN);
        dp[0] = 0;
        for(int i = 1; i<=n; ++i)
        {
            for(int j = 1; j<=i; ++j)
                dp[i] = max(dp[i],price[j-1]+dp[i-j]);
        }
        return dp[n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends