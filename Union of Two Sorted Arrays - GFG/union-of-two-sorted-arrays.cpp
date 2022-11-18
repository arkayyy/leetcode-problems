//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //arr1,arr2 : the arrays
    // n, m: size of arrays
    //Function to return a list containing the union of the two arrays. 
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        vector<int> ans;
        int i = 0, j = 0, curr;
        while(i<n && j<m)
        {
            if(arr1[i]==arr2[j]) {
                curr = arr1[i];
                while(i<n && arr1[i]==curr) ++i;
                while(j<m && arr2[j]==curr) ++j;
                ans.emplace_back(curr); 
            }
            
            else if(arr1[i]<arr2[j]) {
                curr = arr1[i];
                while(i<n && arr1[i]==curr) ++i;
                ans.emplace_back(curr);}
            else {
                curr = arr2[j];
                while(j<m && arr2[j]==curr) ++j;
                ans.emplace_back(curr);}
        }
        while(i<n) {curr = arr1[i];
                while(i<n && arr1[i]==curr) ++i;
                ans.emplace_back(curr);}
        while(j<m) {curr = arr2[j];
                while(j<m && arr2[j]==curr) ++j;
                ans.emplace_back(curr);}
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--){
	    
	    
	    
	    int N, M;
	    cin >>N >> M;
	    
	    int arr1[N];
	    int arr2[M];
	    
	    for(int i = 0;i<N;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<M;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    vector<int> ans = ob.findUnion(arr1,arr2, N, M);
	    for(int i: ans)cout<<i<<' ';
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends