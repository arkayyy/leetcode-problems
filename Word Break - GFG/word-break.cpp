// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
vector<vector<int>> dp;
    int util(int i, int j, string& s, unordered_set<string>& set)
    {
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j]; 
        string s1 = s.substr(i,j-i+1);
        bool res = set.find(s1)!=set.end();
        for(int t = i; t<j; ++t)
        {
            res = res||(util(i,t,s,set)&&util(t+1,j,s,set));
        }
        
        return dp[i][j] = res;
    }
    int wordBreak(string A, vector<string> &B) {
        unordered_set<string> set(B.begin(),B.end());
        dp = vector<vector<int>> (A.size(),vector<int>(A.size(),-1));
        return util(0,A.size()-1,A,set);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}
  // } Driver Code Ends