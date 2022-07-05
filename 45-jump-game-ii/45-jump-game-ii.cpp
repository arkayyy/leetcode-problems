class Solution {
public:
    int jump(vector<int>& nums) {
        //Most optimal Greedy/BFS Solution:- O(N) Time O(1) Space
        //Since here if we at an index i, we can move any no. of steps from 0 to nums[i],
        //therefore we can do it using greedy basis to reach the max possible index from that index
        
        //[start,end] is the range of the elements that we could jump to from previous index
        int start = 0, end = 0, maxend = 0;
        int step = 0;
        while(end<nums.size()-1)
        {
            ++step; 
            for(int i = start; i<=end; ++i)
            {
                if(i+nums[i]>=nums.size()-1) return step; //can reach end
                maxend = max(maxend,i+nums[i]); //storing max index we can jump to from current index
            }
            //updating [start,end] range for our next check:-
            start = end+1;
            end = maxend;
        }
        return step;
    }
};