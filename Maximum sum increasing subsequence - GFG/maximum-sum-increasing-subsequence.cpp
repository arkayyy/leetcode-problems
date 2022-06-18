// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
		

	public:
	int util(int i, int prevIdx,  int arr[], int n,vector<vector<int>> &dp)
	{
	    if(i==n) {return 0;}
	    
	    if(dp[i][prevIdx+1]!=-1) dp[i][prevIdx+1];
	    
	    int res = 0;
	    if(prevIdx==-1 || arr[i]>arr[prevIdx]) res = arr[i]+util(i+1,i,arr,n,dp);
	    
	    res = max(res,util(i+1,prevIdx,arr,n,dp));
	    
	    return dp[i][prevIdx+1] = res;
	}
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	   // vector<vector<int>> dp(n,vector<int>(n+1,-1));
	    //return util(0,-1,arr,n,dp);
	    vector<int> dp(n);
	    for(int i = 0; i<n; ++i) dp[i] = arr[i];
	    for(int i =0; i<n;++i)
	        for(int j = 0; j<i; ++j)
	            if(arr[i]>arr[j] && dp[j]+arr[i]>dp[i])
	                dp[i] = arr[i]+dp[j];
	   return *max_element(dp.begin(),dp.end());
	}  
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends