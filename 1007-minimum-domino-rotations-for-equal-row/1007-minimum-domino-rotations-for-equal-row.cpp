class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        unordered_map<int,vector<int>> mp;
        
        //counting frequency of number in tops and bottoms
        for(int i = 0; i<tops.size(); i++)
        {
            if(mp.find(tops[i])==mp.end())
                mp[tops[i]] = {0,0};
            mp[tops[i]][0]++;
            if(mp.find(bottoms[i])==mp.end())
                mp[bottoms[i]] = {0,0};
            mp[bottoms[i]][1]++;
        }
        
        //handling case for equal elements in both tops and bottoms at same index
        for(int i = 0; i<tops.size(); i++)
        {
            if(tops[i]==bottoms[i])
            {
                //decreasing frequency of a number from tops or bottoms wherever lower count is present
                //REASON: we need to eliminate the effect of equal elements, because there is no use of swapping them
                if(mp[tops[i]][0]<mp[tops[i]][1]) 
                    mp[tops[i]][0]--;
                else
                    mp[tops[i]][1]--;
            }
        }
        
        int el = -1;
        
        for(auto m: mp)
            if(m.second[0]+m.second[1]==tops.size()) //if total frequency of in place elements + swapped elements == tops.siz() or bottoms.size()
            {el = m.first; break;}
        
        if(el==-1)
            return -1;
        
        return min(mp[el][0], mp[el][1]);
    }
};