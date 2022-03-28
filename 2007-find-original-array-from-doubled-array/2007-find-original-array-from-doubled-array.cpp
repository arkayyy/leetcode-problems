class Solution {
public:
    //Similar to: LC954 - Array of Doubled Pairs
    
    //INTUITION: keep pairing every even number with its half. If nos. are left which can't be paired return empty array!
    
    //ALGO: store frequencies in a map and keep decreasing as nos. are paired
    vector<int> findOriginalArray(vector<int>& changed) {
        if(changed.size()&1) //can't be paired if even length
            return {};
        
        map<int,int> mp; //ordered map taken to later traverse them in ordered fashion
        vector<int> ans;
        for(auto c: changed)
            mp[c]++;
        
        for(auto m = mp.rbegin(); m!=mp.rend(); m++) //moving in +ve nos. in descending order because, we check for pairing a number with its half (which is smaller than the no. itself)
            //by doing this a lot of iterations will be saved!
        {
            int num = (*m).first, freq = (*m).second;
            if(num==0) 
            {
                if(freq&1)//since 0 can only be paired with itself, so even freq must be present
                    return {};
                else //for handling the edge case of all zeros in the array
                    for(int i = 0;i<freq/2; i++)
                        ans.push_back(num);
                continue;
            }
            
            if(num&1) return {}; //any odd number encountered must be the half of a bigger even no. processed earlier, 
            //and it must have been paired with that even no. already
            //SO the frequency of the half must have already been reduced to 0 earlier, so we can't encounter any odd no. with freq>0
            
            if(mp[num/2]==0 || mp[num/2]<freq) return {}; 
            
            for(int i = 0;i<freq; i++)
                ans.push_back(num/2);
            
            (*m).second = 0, mp[num/2]-=freq;
            if(mp[num/2]==0) mp.erase(num/2);
        }
        
        return ans;
        
    }
};