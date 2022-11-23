//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
        unordered_set<int> as(arr, arr+N);
        int ans = 0;
        for(int i = 0; i<N; ++i)
        {
            if(as.find(arr[i]-1)!=as.end()) continue;
            int j = 0, cnt = 0;
            while(as.find(arr[i]+j)!=as.end()) {++cnt; as.erase(arr[i]+(j++));}
            ans = max(ans,cnt);
        }
        return ans;
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends