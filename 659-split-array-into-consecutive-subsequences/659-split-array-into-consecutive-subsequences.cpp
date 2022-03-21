class Solution {
public:
    bool isPossible(vector<int>& nums) {
        //INTUITION: Every element in nums can be considered as:
        //(i) tail of a sequence of length >= 3
        //(ii) starting of a sequence with min. length = 3
        
        //ALGO: For every element i in nums
        //(i) we check if there is already considered a sequence tailed at i-1. So now the new tail is modified to i.
        //(ii) we check if i+1 and i+2 exist and can be included along with i in a new sequence.
        //else...the sequence can't be formed so return FALSE.
        
        unordered_map<int,int> freq;
        unordered_map<int,int> tail;
        
        for(auto n: nums)//counting frequency of every number
            freq[n]++;
        
        for(auto n: nums)
        {
            if(!freq[n]) continue;
            
            freq[n]--;
            if(tail[n-1]>0) // case (i)
            {
                //modifying and setting new tail to n
                tail[n-1]--;
                tail[n]++;
            }
            else if(freq[n+1]>0 && freq[n+2]>0) //case (ii)
            {
                freq[n+1]--;
                freq[n+2]--;
                tail[n+2]++; //setting new tail to n+2
            }
            else
                return false;
        }
        
        return true;
    }
};