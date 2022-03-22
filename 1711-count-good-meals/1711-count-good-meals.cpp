class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        
        unordered_map<int,int> mp;
        long long cnt = 0;
        
        for(auto d: deliciousness)
        {
            for(int i = 1; i<=(1<<22); i*=2) //checking with all powers of 2, if (power of 2 - deliciousness) valued deliciousness has already been encountered
                if(mp.find(i-d)!=mp.end())
                    cnt+=mp[i-d]; //if yes, we increase the count
            mp[d]++; 
        }
        
        return (cnt%(int)(1e9+7));
    }
};