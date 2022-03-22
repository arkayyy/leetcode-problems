class Solution {
public:
    int longestWPI(vector<int>& hours) {
        unordered_map<int,int> mp;
        
        int result =0, sum = 0;
        
        for(int i = 0; i<hours.size(); i++)
        {
            sum += (hours[i]>8)?1:-1; //adding 1 for tiring and -1 for not tiring
            
            if(sum>0) //if starting from 0 index to i, net tiring is more than non-tiring days
                result = i+1; //storing i+1 since 0-based indexing in array
            else //if number of non-tiring days is equal to or more than tiring days
            {
                if(mp.find(sum-1)!=mp.end()) //since we need positive sum(i.e. tiring days > non-tiring days), that can only reside between appearance of sum and sum-1
                    result = max(result,i-mp[sum-1]);
            }
            
            if(mp.find(sum)==mp.end()) //marking occurence index of every sum (cumulative) if not already marked
                mp[sum] = i;
        }
        return result;
    }
};