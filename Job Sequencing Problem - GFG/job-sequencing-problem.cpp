// { Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


 // } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    struct profitSort{
        bool operator()(auto&a,auto&b)
        {
            return a.profit<b.profit;
        }
    };
    
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // sort(arr,arr+n,[&](auto&a,auto&b){ return a.profit>b.profit; });
        // int slots[n], result[n];
        // int cnt = 0, profit =0;
        // memset(slots,0,sizeof(slots));
        // for(int i = 0; i<n; ++i)
        //     for(int j = min(arr[i].dead,n)-1; j>=0; --j)
        //         if(!slots[j])
        //         {
        //             //result[j] = i, 
        //             slots[j] = 1;
        //             ++cnt,profit+= arr[i].profit;
        //             break;
        //         }
                
        // return {cnt,profit};
        
        sort(arr,arr+n,[&](auto&a, auto&b){return a.dead<b.dead;});
        priority_queue<Job,vector<Job>,profitSort> pq;
        int cnt = 0,profit = 0;
        for(int i = n-1; i>=0; --i)
        {
            int freeSlots = 0;
            freeSlots = i==0?arr[i].dead:arr[i].dead-arr[i-1].dead;
            pq.push(arr[i]);
            while(freeSlots && !pq.empty())
            {
                --freeSlots,++cnt;
                profit+=pq.top().profit;
                pq.pop();
            }
        }
        
        return {cnt,profit};
        
    }   
};

// { Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}


  // } Driver Code Ends