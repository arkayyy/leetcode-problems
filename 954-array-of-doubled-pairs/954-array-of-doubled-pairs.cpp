class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        map<int,int> pos, neg;
        int p = 0, n = 0;
        for(auto a: arr)
        {
            if(a>=0)
               {p++; pos[a]++;}
            else
               {n++; neg[a]++;}
        }
        if((p&1) || (n&1))
            return false;
        
        
        
        for(auto m = pos.rbegin(); m!=pos.rend();m++)
        {
            int num = (*m).first;
            
            int freq = (*m).second;
            cout<<num<<" "<<freq<<endl;
            if(num==0)
            {
                if((freq&1))
                    return false;
            }
            else if(freq>0)
            {
                if(num&1) return false;
                if(pos[num>>1]==0 || pos[num>>1]<freq)
                    return false;
                (*m).second = 0 ;
                pos[num>>1] -= freq;
            }
        }
        
        for(auto m = neg.begin(); m!=neg.end();m++)
        {
            int num = (*m).first;
            
            int freq = (*m).second;
            cout<<num<<" "<<freq<<endl;
            if(freq>0)
            {
                if((abs(num))&1) return false;
                
                if(neg[num/2]==0 || neg[num/2]<freq)
                    return false;
                (*m).second = 0 ;
                neg[num/2] -= freq;
            }
        }

        return true;
    }
};