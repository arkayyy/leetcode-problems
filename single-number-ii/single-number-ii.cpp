class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        vector<int> binaryBits(32,0);
        
        for(int i = 0;i<32;i++)
        {
            for(auto j:nums)
            {
                if((j&(1<<i)))
                    binaryBits[i]++;
            }
        }
        
        int singleNo = 0;
        
        for(int i=0;i<32;i++)
        {
            if(binaryBits[i]%3 != 0)
                singleNo = ((1 << i) | singleNo);
        }
        
        return singleNo;
        
    }
};