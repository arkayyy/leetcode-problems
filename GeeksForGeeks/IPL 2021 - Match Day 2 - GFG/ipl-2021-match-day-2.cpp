// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        vector<int> ans;
        
        //DEQUE SOLUTION:-
        // deque<int> dq;
        
        // int i=0;
        // while(i<n)
        // {
        //     while(!dq.empty() && dq.front()==i-k)
        //         dq.pop_front();//popping all element indexes from deque which don't fall in the current group of k indexes
            
        //     while(!dq.empty() && arr[dq.back()]<arr[i])
        //         dq.pop_back();  // we keep popping back all other elements(their indexes) from deque which are smaller than the new element arr[i]
            
        //     dq.push_back(i); //pushing current index
            
        //     if(i>=k-1) //we can push the maximum in the array only after starting (k-1) elements of the array, not before them. 
        //     //(min size of every group is k)
        //         ans.push_back(arr[dq.front()]);
            
        //     i++;
        // }
        
        
        //PRIORITY QUEUE SOLUTION:-
        priority_queue<vector<int>> pq;
        int lo=0,hi=0;
        
        while(hi<n)
        {
            if(hi-lo+1 < k)
            {
                pq.push({arr[hi],hi});
                hi++;
            }
            else
            {
               pq.push({arr[hi],hi});
               int temp = pq.top()[0];
               ans.push_back(temp); //storing the max element of the current k group
               while(!pq.empty())
               {
                   if(pq.top()[1] <= lo) //if index current max as per pq lies outside of the current group of k elements
                        pq.pop();
                        
                    else //if the max element of as per the pq is present in the current group
                        break; //so no need to continue
               }
               lo++, hi++;
            }
        }
        
        
        return ans;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;
        vector<int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}  // } Driver Code Ends