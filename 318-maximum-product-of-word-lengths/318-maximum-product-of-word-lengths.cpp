class Solution {
public:
    //unordered_map<int,vector<int>> mp;
    unordered_map<int,int> mp;
    //bool commChar(vector<int>& freq1, vector<int>&freq2)
    bool commChar(int& freq1, int& freq2)
    {
        for(int i = 0; i<26; ++i)
            //if(freq1[i]>0 && freq2[i]>0) return true;
            if((freq1 & (1<<i)) && (freq2 & (1<<i))) return true;
        return false;
    }
    int maxProduct(vector<string>& words) {
        for(int i = 0; i<words.size(); ++i)
        {
            //mp[i] = vector<int>(26,0);
            mp[i]= 0;
            for(auto c: words[i]) 
                //++mp[i][c-'a'];
                mp[i] = mp[i] | (1<<(c-'a'));
        }
        
        int ans = 0;
        
        for(int i = 0; i<words.size(); ++i)
            for(int j = 0; j<words.size(); ++j)
                if(i!=j && !commChar(mp[i],mp[j]))
                    ans = max(ans, (int)words[i].size() * (int)words[j].size());
        
        return ans;
    }
};