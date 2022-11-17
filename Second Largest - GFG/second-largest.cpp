//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// Function returns the second
	// largest elements
	int print2largest(int arr[], int n) {
        int maxi1 = INT_MIN, maxi2 = INT_MIN;
        for(auto i = 0; i<n; ++i) {
            if(arr[i]>maxi1) {maxi2 = max(maxi1,maxi2); maxi1 = arr[i]; }
            else if(arr[i]>maxi2 && arr[i]!=maxi1) {maxi2 = arr[i];}
        }
        return maxi2==INT_MIN?-1:maxi2;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.print2largest(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends