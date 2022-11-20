//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> nextPermutation(int N, vector<int> arr){
        int i = arr.size()-1;
        while(i>0)
        {
            if(arr[i]>arr[i-1]) break;
            
            --i;
        }
        
        if(i==0) reverse(arr.begin(),arr.end());
        else
        {
            int j = i, mini = INT_MAX, ind = i-1;
            while(j<arr.size())
            {
                if(arr[j]>arr[i-1])
                {
                    if(arr[j]<mini)
                    {
                        mini = arr[j];
                        ind = j;
                    }
                }
                ++j;
            }
            swap(arr[i-1],arr[ind]);
            reverse(arr.begin()+i,arr.end());
        }
        
        return arr;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends