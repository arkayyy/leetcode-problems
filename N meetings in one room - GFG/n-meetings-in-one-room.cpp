// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    bool static comparator(vector<int>& m1, vector<int>& m2) {
         if (m1[1] < m2[1]) return true;
         else if (m1[1] > m2[1]) return false;
         else if (m1[2] < m2[2]) return true;
         return false;
      }
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        
        vector<vector<int>> arr;
        for(int i = 0; i<n; ++i)
        arr.push_back({start[i],end[i],i});
        sort(arr.begin(),arr.end(),comparator);
        int cnt = 1;
        int prevEnd = arr[0][1];
        for(int i = 1; i<n; ++i)
        {
            if(arr[i][0] > prevEnd)
                ++cnt, prevEnd = arr[i][1];
        }
        return cnt;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends