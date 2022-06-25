// { Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
vector<vector<int>> dp;
//Partition DP
    bool isPalin(int i,int j, string&s)
    {
        while(i<j)
            if(s[i++]!=s[j--]) return false;
        return true;
    }
    
    // int util(int i,int j, string& s)
    // {
    //     if(i>j) return 0;
        
    //     if(isPalin(i,j,s)) return 0;
        
    //     if(dp[i][j]!=-1) return dp[i][j];
        
    //     int res = INT_MAX;
    //     for(int t = i; t<j;++t)
    //         if(isPalin(i,t,s))
    //             res = min(res, 1+util(t+1,j,s));
                
    //     return dp[i][j] = (res==INT_MAX?0:res);
    // }
    
    int util(int i, int j,string&s)
    {
        if(i==j) return 0;
        if(isPalin(i,j,s)) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        
        int res = INT_MAX;
        for(int t = i+1; t<=j; ++t)
            res = min(res, 1+util(i,t-1,s)+util(t,j,s));
        return dp[i][j] = res;
    }
    int palindromicPartition(string str)
    {
        dp = vector<vector<int>> (str.size(),vector<int>(str.size(),-1));
        return util(0,str.size()-1,str);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  // } Driver Code Ends