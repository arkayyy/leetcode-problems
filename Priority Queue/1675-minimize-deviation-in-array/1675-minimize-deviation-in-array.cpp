class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        //===================APPROACH - 1 - O(NlogN) =================================================//
//         priority_queue<int> pq;
//         int mini = INT_MAX, maxi = INT_MIN;
//         for(int i = 0; i<nums.size(); i++)
//         {
//             if(nums[i]&1)
//                 nums[i]*=2;
//             maxi = max(maxi,nums[i]);
//             mini = min(mini,nums[i]);
//         }
        
//         int min_diff = maxi - mini;
        
//         for(int i = 0; i<nums.size(); i++)
//             pq.push(nums[i]);
        
//         while(pq.top()%2==0) //we can only continue unitl pq.top() is even..because if the maximum number in the array now is odd, it can't further be divided by 2
//         {
//             int t = pq.top();
//             pq.pop();
//             min_diff = min(min_diff, t-mini);
//             t/=2;
//             mini = min(mini,t); //only updating mini(global minimum) here because we are only dividing the even numbers by 2 and storing them again in the PQ. So no chance of any number increasing here...
//             pq.push(t);// pushing again the top as we have to minimize the max
//         }
        
//         min_diff = min(min_diff, pq.top()-mini); //pq.top() will at last contain the element that is the most minimized max...and mini will contain the global minimum in the array
        
//         return min_diff;
        
        
        
        //----------------------------------APPROACH 2 - SET approach O(NlogN) time O(N) space--------------------------------//
        set<int> s;
        for(int i = 0; i<nums.size(); i++)
        {
            if(nums[i]&1)
                s.insert(nums[i]*2);
            else
                s.insert(nums[i]);
        }
        
        
        int min_diff = *s.rbegin() - *s.begin();
        
        while(*s.rbegin() %2==0)
        {
            int maxi = *s.rbegin();
            s.erase(maxi);
            s.insert(maxi/2); //here we don't need to store and update global mini separately, it is automatically stored and accessed from the set
            min_diff = min(min_diff, *s.rbegin()-*s.begin());
        }
        
        return min_diff;
    }
};