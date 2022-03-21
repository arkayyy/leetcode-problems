class Solution {
public:
    vector<int> partitionLabels(string s) {
        //INTUITION: For every character, the rightmost appearance index of that character must be the minimum length of string to consider. 
        //Because no character can lie in multiple partitions. So all occurences (last one being the rightmost appearance) should lie in a single partition.
        
        //ALGO: We fix a range from start to limit, and if any character lies in this range whose rightmost appearance falls ahead/after limit index, we shift limit to that ahead index.
        //At end of every iteration, we push back length between start and limit to our answer.
        
        unordered_map<char, int> mp; //marking rightmost appearance of every character
        
        for(int i = 0; i<s.length(); i++)
        {
            if(mp.find(s[i])!=mp.end())
                continue;
            
            int j = s.length()-1;
            while(s[j]!=s[i])
                j--;
            mp[s[i]] = j;
        }
        
        // for(auto m: mp)
        // {
        //     cout<<m.first<<" "<<m.second<<endl;
        // }
        
        
        int i = 0;
        int start = 0;
        int limit = mp[s[0]];
        
        vector<int> ans;
        while(start<s.size())
        {
            for(int i = start; i<=limit; i++)
            {
                if(mp[s[i]] > limit)  //if any character b/w start and limit whose index lies ahead of limit, we extend the limit
                {
                    limit = mp[s[i]];
                }
            }

            ans.push_back(limit-start+1); //pushing length b/w start and limit
            start = limit+1;
            if(start<s.size())
                limit = mp[s[start]];
            
        }
        
        
        return ans;
        
        
    }
};