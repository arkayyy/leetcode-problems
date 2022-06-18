// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dp[100][100];
    int util(int i, int j, int N, int arr[])
    {
        if(i==j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int res = INT_MAX;
        for(int k = i; k<j;++k)
            res = min(res, arr[i-1]*arr[k]*arr[j] + util(i,k,N,arr)+util(k+1,j,N,arr));
        return dp[i][j] = res;
    }
    int matrixMultiplication(int N, int arr[])
    {
        memset(dp,-1,sizeof(dp));
        return util(1,N-1,N,arr);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}  // } Driver Code Ends