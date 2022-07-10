class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        long long curr = 0;
        deque<int> dq;//monotonic dequeue (will always have max element at front, just like a max heap)
        
        
        //WE are doing tabulation here. Since we have to reach nums.size()-1 at last, so our base case is at that index. 
        //That's why we start traversing from nums.size()-1
        for(int i = nums.size()-1; i>=0; --i)
        {
            curr = nums[i]+(dq.empty()?0:nums[dq.front()]); //maximum score/element containing index will be at the front of the deque 
            //so the score at reaching the next index will be = nums[i] + (score from index at front of the queue) 
            //(NOTE: at nums[i] we have already memoised the maximum score attained at reaching this index,
            //we can also take a separate array for doing this memoization)
            while(!dq.empty() && curr> nums[dq.back()])//popping all indexes containing scores less than current score, because they are useless since we need to maximize the score
                dq.pop_back();
            dq.push_back(i); //pushing current index into deque for further maximization of score
            while(dq.front()>=i+k)//popping all the indexes that lie out of the k range
                dq.pop_front();
            nums[i] = curr; //max score attained at reaching next index from current index i
        }
        return curr;
    }
};