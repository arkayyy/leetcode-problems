//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	void pushZerosToEnd(int arr[], int n) {
	    int i = -1, j = 0, nz = 0;
	    while(j<n)
	    {
	        if(arr[j]==0)
	        {
	            if(i==-1) i = j;
	            ++j;
	        }
	        else
	        {
	            ++nz;
	            if(i!=-1) arr[i++] = arr[j];
	            ++j;
	        }
	    }
	    for(int k = nz; k<n; ++k) arr[k]= 0;
	}
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.pushZerosToEnd(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends