class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        
        //1. USING PRIORITY QUEUE AND 2-POINTER:-
        priority_queue<vector<int>> pq;
        int lo=0,hi=0;
        
        while(hi<nums.size())
        {
            if(hi-lo+1 < k)
            {
                pq.push({nums[hi],hi});
                hi++;
            }
            else
            {
               pq.push({nums[hi],hi});
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
        
        
        //NOTE: USING DEQUE, the method won't work for negative elements in the array
        
        return ans;
    }
};